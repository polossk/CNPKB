# Inkscape 使用备注

> tags: #svg; #format-converter; #inkscape;

主要参考文档<a name="rref1"></a>\[[1](#ref1)\]。

## MacOS 命令行启动方式

在 zsh 的配置文件 `~/.zshrc` 中添加别名

```shell
alias inkscape="/Applications/Inkscape.app/Contents/MacOS/Inkscape"
```

随后在命令行中输入 `inkscape` 来启动软件，或者直接执行命令。这样做的目的是为了保证在后续的使用中可以直接调用当前的所有环境变量。

## 格式转换

```shell
inkscape --export-type=png,pdf figure.svg
```

## 输入数学公式

1. 菜单栏中依次选择“Extension -> Render -> Mathematics -> LaTeX”打开工具箱；
2. 输入 $\LaTeX$ 代码，注意数学公式需要手动输入数学环境 `$\mathrm{e}^{i\pi} + 1 = 0$` 才能正确渲染为数学公式 $\mathrm{e}^{i\pi} + 1 = 0$；
3. 关于字体大小问题：Inkscape 的输出字体大小存在问题，具体表现为虽然可以通过 `fontsize{11pt}{13.75pt}` 控制大小为 11pt，但是与真实的 11pt 有较大出入，实际输出结果约为 29pt，非常的不伦不类。所以可以事先记录一些标准高度，然后将对应的数学公式的高度等比例放缩既可。

|     展示目的      |      字号      | 实际高度 | 换算比例 |
| :---------------: | :------------: | :------: | :------: |
| 默认（论文与PPT） | 11pt（大五号） | 2.821mm  | (11/29)  |
|       大图        |  14pt（四号）  | 3.590mm  | (14/29)  |
|      超大图       |  22pt（二号）  | 5.642mm  | (22/29)  |

## 改变背景页面大小

1. 菜单栏中依次选择“File -> Document Properties”或快捷键 Ctrl + Shift + D 打开文档属性；
2. 默认文档页面大小为 A4 纸张大小（210mm x 297mm）；
3. 自定义尺寸框内，点击缩放页面到内容，设置边距；
4. 点击缩放页面到绘图或选区，快捷键为 Ctrl + Shift + R。

## 软件下载

官网网址 <https://inkscape.org/release/>

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Inkscape 命令行文档 <https://inkscape.org/doc/inkscape-man.html>
