# MATLAB 基础配置

> tags: #matlab; #utf-8

## 将 MATLAB 的字符集编码更改为 UTF-8

* 在命令窗口输入命令查看当前编码方式<a name="rref1"></a>\[[1](#ref1)\]：
    ```matlab
    feature('DefaultCharacterSet')
    feature('locale')
    current = slCharacterEncoding()
    ```
* 如果要将编码方式更改为 UTF-8 编码，需要编辑 MATLAB 的 locale 数据库文件 `lcdata.xml`<a name="rref2"></a>\[[2](#ref2)\]。
* 在 Matlab 安装目录中找到 `lcdata_utf8.xml` 文件（其默认路径为 `<matlab_install_path>\bin`），并将其重命名为 `lcdata.xml`。
* 在文件中删除
    ```xml
    <encoding name="GBK">
        <encoding_alias name="936">
    </encoding>
    ```
* 定位
    ```xml
    <encoding name="UTF-8">
        <encoding_alias name="utf8"/>
    </encoding>
    ```
* 修改为
    ```xml
    <encoding name="UTF-8">
        <encoding_alias name="utf8"/>
        <encoding_alias name="GBK"/>
    </encoding>
    ```

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Specify encoding to use in code generated from Simulink models - MATLAB slCharacterEncoding <https://www.mathworks.com/help/simulink/slref/slcharacterencoding.html>
<a name="ref2">\[2\]</a>[^](#rref2) How do I get my MATLAB editor to read UTF-8 characters? UTF-8 characters in blank squares in editors, but in the command window and workspace works fine. - MATLAB Answers <https://www.mathworks.com/matlabcentral/answers/280988-how-do-i-get-my-matlab-editor-to-read-utf-8-characters-utf-8-characters-in-blank-squares-in-editors/>

