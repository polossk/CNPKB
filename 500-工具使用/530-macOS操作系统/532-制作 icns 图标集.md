# 制作 icns 图标集

> tags: #macOS; #icon; #icns; #图标

> **TL; DR**: 制作不同尺寸的图标然后用命令打包即可

## icns 文件

`icns` 是 Apple 的 macOS 操作系统的 App 图标文件的扩展名，你在 macOS 系统内所看到应用程序的外观就是由一个内置在此 App 内部的扩展名为 `icns` 的文件实现的。

通过鼠标右键点击 App - 显示包内容 - 进入 Contents 目录 - 进入Resources 目录，然后在目录下可以找到名为`Appicon.icns`或其他后缀为 `icns` 的一个图标文件。

## 制作流程

为了制作一个 `icns` 图标文件，需要准备以下 10 种不同大小的图片文件，并且文件前缀**必须**以 `icon` 开头。以 `png` 文件为例：

| 图片名称              |  图片大小 |
| :-------------------- | --------: |
| `icon_16x16.png`      |     16x16 |
| `icon_16x16@2x.png`   |     32x32 |
| `icon_32x32.png`      |     32x32 |
| `icon_32x32@2x.png`   |     64x64 |
| `icon_128x128.png`    |   128x128 |
| `icon_128x128@2x.png` |   256x256 |
| `icon_256x256.png`    |   256x256 |
| `icon_256x256@2x.png` |   512x512 |
| `icon_512x512.png`    |   512x512 |
| `icon_512x512@2x.png` | 1024x1024 |

所以，我们需要事先准备一个高分辨率的 1024x1024 的原始图片，然后将其缩减为上述表格中尺寸要求下的图片，最后打包到一个 `icns` 文件当中。

1. 整理并准备一张最大尺寸的源图片 `icon.png`；
2. 为方便后续打包，创建一个文件夹 `icons.iconset`，将后续的缩减尺寸的图片保存至此，相关命令如下
    ```shell
    mkdir icons.iconset
    ```
3. 可以通过命令来快速创建不同尺寸的图片，也可以使用其他图像处理软件（如 Photoshop 等）
    ```shell
    sips -z 16 16 icon.png -o icons.iconset/icon_16x16.png
    sips -z 32 32 icon.png -o icons.iconset/icon_16x16@2x.png
    sips -z 32 32 icon.png -o icons.iconset/icon_32x32.png
    sips -z 64 64 icon.png -o icons.iconset/icon_32x32@2x.png
    sips -z 128 128 icon.png -o icons.iconset/icon_128x128.png
    sips -z 256 256 icon.png -o icons.iconset/icon_128x128@2x.png
    sips -z 256 256 icon.png -o icons.iconset/icon_256x256.png
    sips -z 512 512 icon.png -o icons.iconset/icon_256x256@2x.png
    sips -z 512 512 icon.png -o icons.iconset/icon_512x512.png
    sips -z 1024 1024 icon.png -o icons.iconset/icon_512x512@2x.png
    ```
4. 输入打包命令，将文件夹 `icons.iconset` 内的图片打包，`icon.icns` 就是最终的输出文件
    ```shell
    iconutil -c icns icons.iconset -o icon.icns
    ```


## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) App Icons - Foundations - Human Interface Guidelines - Design - Apple Developer <https://developer.apple.com/design/human-interface-guidelines/foundations/app-icons/>
