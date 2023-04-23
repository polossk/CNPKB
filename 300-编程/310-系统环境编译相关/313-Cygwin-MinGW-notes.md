# Cygwin-MinGW 环境配置

> tags: #Cygwin; #MinGW

## 相关软件

| 相关软件                                     |                                           可下载网址                                            |          版本与最近更新时间 |
| :------------------------------------------- | :---------------------------------------------------------------------------------------------: | --------------------------: |
| Cygwin <a name="rref1"></a>\[[1](#ref1)\]    |                                                                                                 |          3.4.6 (2023-04-18) |
| MinGW-w64 <a name="rref2"></a>\[[2](#ref2)\] | Windows GCC 8.1.0 <a name="rref3"></a>\[[3](#ref3)\], 12.2.0 <a name="rref4"></a>\[[4](#ref4)\] | 8.1.0与 12.2.0 (2023-04-18) |

## Cygwin 安装与配置

1. 下载设置选择 `Install from Internet`
2. 网络连接设置选择 `Use System proxy settings`
3. 下载源添加合适的镜像 <https://mirrors.tuna.tsinghua.edu.cn/cygwin/> <a name="rref5"></a>\[[5](#ref5)\]
4. 添加核心组件：`automake`，`curl`，`expect`，`gcc-core`，`gcc-g++`，`gdb`，`git`，`lynx`，`make`，`openssh`，`vim`，`wget`
5. 等待安装
6. 将安装目录（默认为 `C:\cygwin64\bin`）添加至环境变量 `PATH`
7. Windows 目录挂载在 `/cygdrive/` 下，例如电脑 D 盘的文件 `D:\folder\hellowor1d.cpp` 在 Cygwin 的目录为 `/cygdrive/d/folder/helloworld.cpp`

## MinGW 安装与配置

1. 按照上述流程，Cygwin 会安装好 GCC 相关的编译器，安装 MinGW 是为了在 Windows 环境中开发时更方便编译文档
2. 直接从链接中下载对应的压缩包，解压到 C 盘根目录中即可
	1. 省流：64 位 windows 10 新电脑开发 Windows 程序选择 `x86_64-X.Y.Z-release-win32-seh-ucrt`
	2. 操作系统架构：`i686` 构建 32 位程序，`x86_64` 构建 64 位程序
	3. 异常实现模型：`dwarf` 只适用于 32 位程序，`seh` 只适用于 64 位程序，`sjlj`（setjmp/longjmp）适合 32 或 64 位程序，但是会带来性能损失
	4. 线程模型与操作系统接口协议：`posix` 支持 C++11 多线程特性，`win32` 不支持 C++11 多线程特性，且只支持 Windows 操作系统
	5. C Runtime 运行时库：`msvert`（Microsoft visual C Runtime）旧版本（Win10 之前）的运行时库，`ucrt`（Universal C Runtime）是 Win10 版本的新运行时库
3. 将安装目录（默认为 `C:\mingw64\bin`）添加至环境变量 `PATH`
4. 为了更方便使用，建议将 `C:\mingw64\bin` 中的 `mingw32-make.exe` 可执行文件复制一份，并重命名为 `make`，保持操作习惯的统一

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Cygwin <https://cygwin.com/>

<a name="ref2">\[2\]</a>[^](#rref2) MinGW-w64 <https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html>

<a name="ref3">\[3\]</a>[^](#rref3) MinGW-w64 - for 32 and 64 bit Windows Files <https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>

<a name="ref4">\[4\]</a>[^](#rref4) Releases · niXman/mingw-builds-binaries <https://www.gnu.org/software/make/manual/html_node/index.html>

<a name="ref5">\[5\]</a>[^](#rref5) Cygwin 镜像使用帮助 <https://mirrors.tuna.tsinghua.edu.cn/help/cygwin/>