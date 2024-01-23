# Makefile 使用备注

> tags: #Makefile;

## 跨平台适用的 LaTeX 编译脚本

```makefile
TEX      = xelatex
BIB      = bibtex
MAIN     = article-local
TEXARGS  = -synctex=1

ifeq ($(OS), Windows_NT)
    PLATFORM = Windows
else
    ifeq ($(shell uname), Darwin)
        PLATFORM = MacOS
    else
        PLATFORM = Unix-Like
    endif
endif

ifeq ($(PLATFORM), Windows)
    RM = del /s /f
    OPEN = cmd /c start
    CLOSE = cmd /c taskkill /im Acrobat.exe /t /f
else
    RM = rm -rf
    OPEN = open
    PID = $$(ps -ef | grep AdobeAcrobat | grep -v grep | awk '{print $$2}')
    CLOSE = kill -9 $(PID)
endif

target: close wipe clean tex open

tex: $(MAIN).tex
	$(TEX) $(TEXARGS) $<
	$(TEX) $(TEXARGS) $<

nobib: $(MAIN).tex
	$(TEX) $(TEXARGS) $<
	$(BIB) $(MAIN).aux
	$(TEX) $(TEXARGS) $<
	$(TEX) $(TEXARGS) $<

open: $(MAIN).pdf
	$(OPEN) $(MAIN).pdf

close:
	@$(CLOSE) || echo not found

clean:
	$(RM) *.aux *.bbl *.blg *.log *.out *.gz *.toc *.thm *.fdb_latexmk *.fls *.nav *.snm *.vrb *.spl

wipe:
	$(RM) $(MAIN).pdf

.PHONY: open close clean wipe
```

## 基本语法

每一个 makefile 文件由若干个目标组成，而每一个目标又可以由不同的目标嵌套而成。makefile 的设计初衷是用来完成构建，即只需要给出不同目标的依赖关系，通过拓扑排序即可得到生成顺序，从而构建复杂项目。每一个目标由三部分构成：目标名称，前置依赖和制作方法。如下所示，其中符号 `()*` 表示括号内的内容可以有 0 个或者多个。

```plain
<makeitem> := {
<target>: (<dependency>)*
(<TAB><Command>)*
}
```

### Windows 下的额外设置

这里需要区分编译命令和执行命令。绝大多数编译命令是有明确的产出文件的，而执行命令的范围更广。在 Windows 环境下，部分命令可能需要嵌套 `cmd /c` 壳来使用。比如打开文件的命令 `start`，如果直接写

```makefile
# usage: make open
#   It will open the built PDF file in Windows
open: artical.pdf
	start artical.pdf
```

此时执行这段代码将得到一个奇怪的结果，文件打开了，但是 makefile 报错了。

```plain
process_begin: CreateProcess(NULL, start artical.pdf, ...) failed.
make (e=2): 系统找不到指定的文件。
make: *** [makefile:4: open] Error 2
```

所以如果确定是在 Windows 环境下使用的话，建议套壳，如下代码所示

```makefile
# usage: make open
#   It will open the built PDF file in Windows
open: artical.pdf
	cmd /c start artical.pdf
```

## 设置变量

变量右端默认按照原本的字符串存储，所写即所得。比如一个简单的 C++ 多文件项目，就可以将编译器和编译选项设置为两个变量 `CC` 和 `CXXFLAGS`，从而方便集中控制与管理。后续通过调用 `$(CC)` 和 `$(CXXFLAGS)` 来使用。举例如下所示。

```makefile
CC       = g++ # clang
CXXFLAGS = -std=c++11 -lm

main: main.o a.o
	$(CC) -o main main.o a.o $(CXXFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CXXFLAGS)

a.o: a.cpp a.h
	$(CC) -c a.cpp a.h $(CXXFLAGS)
```

在makefile 内使用 `$$` 表示 shell 中原本的 `$` 符号。举例说明，比如我需要关掉所有的 python 程序，我可以通过编写 `kill -9 $(ps -ef | grep python | grep -v grep | awk '{print $2}')` 来处理。即通过 `grep` 筛选出进程，然后送到 `awk` 中获得进程 PID，最后把结果作为 `kill -9` 命令内关闭进程。这里就出现了两处 `$`，所以在对应的 makefile 内，这个语句可以写为

```makefile
# usage: make close/shutdown/kill
#   It will close python process, not available in Windows
PID = $$(ps -ef | grep AdobeAcrobat | grep -v grep | awk '{print $$2}')
CLOSE = kill -9 $(PID)

close:
	kill -9 $$(ps -ef | grep python | grep -v grep | awk '{print $$2}')
shutdown:
	$(CLOSE)
kill:
	@$(CLOSE)
```

第三个目标的构建语句中出现了 `@` 符号，表示该命令不需要显示在屏幕中，类似于静默处理。而从前两个目标的构建语句的对比可以看出借助变量可以将准备工作与构建语句分离，从而更方便维护代码逻辑。

## 变量的赋值操作

不同的赋值符有不同的含义<a name="rref1"></a>\[[1](#ref1)\]，可参考如下代码。

```makefile
VARIABLE = value  # lazy
VARIABLE := value # immediate
VARIABLE ?= value # if absent
VARIABLE += value # append
```

## 常用自动变量

`make` 还提供了一些简单的内置变量<a name="rref2"></a>\[[2](#ref2)\]，诸如 `$(CC)` 表示默认的C编译器(cc)，`$(CXX)` 表示默认的 C++ 编译器。

常见的自动变量<a name="rref3"></a>\[[3](#ref3)\]有这几个：`$@`，`$<`，`$^`，`$*`，分别表示，构建目标，第一个前置条件，所有前置条件，和匹配符%匹配的部分。

```makefile
a.txt: b.txt c.txt
	echo $@ # => a.txt
	echo $< # => b.txt
	echo $^ # => b.txt c.txt

%.o: %.cpp %.h
	g++ -o $* %^ -std=c++11
```

这样相当于可以轻松地解决大量的重复工作。比如之前的C++项目就可以直接写成这种形式：

```makefile
CC       = g++ # clang
EXEC     = main
OBJ      = a.o b.o main.o
CXXFLAGS = -std=c++11 -lm

$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CXXFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CXXFLAGS)

%.o: %.cpp %.h
	$(CC) -c $^ $(CXXFLAGS)

clean:
	rm -f *.o $(EXEC)

.PHONY: clean
```

## 多平台整合

`make` 提供了 `$(OS)` 变量方便获取系统内核信息，这样就可以利用判断语句 `ifeq ... else ... endif` 对不同的环境进行定制化（主要是填补 Windows 和 *inx 的沟堑）。需要注意的是，`tab` 符号只能出现在命令前，所以为了方便视觉上的整齐，这里的对齐请使用空格。下面的代码是简单的三家平台的区分模板。

```makefile
ifeq ($(OS), Windows_NT)
    PLATFORM = Windows
else
    ifeq ($(shell uname), Darwin)
        PLATFORM = MacOS
    else
        PLATFORM = Unix-Like
    endif
endif
```

## 更多

其他更多内容可以参考 make 文档<a name="rref4"></a>\[[4](#ref4)\]。

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Makefile variable assignment - stackoverflow <http://stackoverflow.com/questions/448910/makefile-variable-assignment>

<a name="ref2">\[2\]</a>[^](#rref2) Implicit-Variables <https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html>

<a name="ref3">\[3\]</a>[^](#rref3) Automatic-Variables <https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>

<a name="ref4">\[4\]</a>[^](#rref4) GNU make <https://www.gnu.org/software/make/manual/html_node/index.html>
