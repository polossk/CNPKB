# MATLAB 配置手册

> tags: #matlab; #utf-8; #config;

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

## 命令行启动 MATLAB

* 添加 MATLAB 目录至 PATH 当中
    ```bash
    # 对于 zsh 用户
    echo '# >>> MATLAB_R2021b >>>' >> ~/.zshrc
    echo 'export PATH=/Applications/MATLAB_R2021b.app/bin/:$PATH' >> ~/.zshrc
    echo '# <<< MATLAB_R2021b <<<' >> ~/.zshrc
    ```
* 使用 `-batch` 选项来执行脚本，比如主代码为 `main.m` 文件，可以这样调用
    ```bash
    matlab -batch "main;exit(0);"
    ```

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Specify encoding to use in code generated from Simulink models - MATLAB slCharacterEncoding <https://www.mathworks.com/help/simulink/slref/slcharacterencoding.html>
<a name="ref2">\[2\]</a>[^](#rref2) How do I get my MATLAB editor to read UTF-8 characters? UTF-8 characters in blank squares in editors, but in the command window and workspace works fine. - MATLAB Answers <https://www.mathworks.com/matlabcentral/answers/280988-how-do-i-get-my-matlab-editor-to-read-utf-8-characters-utf-8-characters-in-blank-squares-in-editors/>
<a name="ref3">\[3\]</a>[^](#rref3) Startup and Shutdown - MATLAB & Simulink <https://www.mathworks.com/help/matlab/startup-and-shutdown.html>
<a name="ref4">\[4\]</a>[^](#rref4) Start MATLAB program from macOS Terminal - MATLAB <https://www.mathworks.com/help/matlab/ref/matlabmacos.html>

