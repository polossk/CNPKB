# Inkscape 使用备注

> tags: #svg; #format-converter; #inkscape;

## 格式转换

```shell
inkscape --export-type=png,pdf figure.svg
```

## 输入数学公式

1. `Extension -> Render -> Mathematics -> LaTeX` 打开工具箱
2. 输入 $\LaTeX$ 代码，注意数学公式需要手动输入数学环境 `$\mathrm{e}^{i\pi} + 1 = 0$` 才能正确渲染为数学公式 $\mathrm{e}^{i\pi} + 1 = 0$

## 改变背景页面大小

1. `File -> Document Properties` 或快捷键 `Ctrl + Shift + D` 打开文档属性
2. 默认文档页面大小为 A4 纸张大小（210mm x 297mm）
3. 自定义尺寸框内，点击缩放页面到内容，设置边距
4. 点击缩放页面到绘图或选区，快捷键 `Ctrl + Shift + R`

## 软件下载

官网网址 <https://inkscape.org/release/>

## 参考文档

1. 命令行文档 <https://inkscape.org/doc/inkscape-man.html>
2. 