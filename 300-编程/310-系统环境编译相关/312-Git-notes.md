# Git 屏蔽所有 .DS_Store 文件

> tags: #git; #macOS; #.DS_Store;

## `.DS_Store` 是什么

英文全名 Apple Desktop Services Store <a name="rref1"></a>\[[1](#ref1)\]，桌面服务存储，是由 macOS 系统自动创建的隐藏文件，用于储存 macOS 下桌面显示相关的一些自定义属性，如文件图标的位置、文件夹上次打开时的窗口大小、桌面位置等。对其他用户或操作系统而言是不必要的文件，类似于 Windows 下的 desktop.ini 文件。

## Git 忽略该文件

参考 <a name="rref2"></a>\[[2](#ref2)\] 这个回答，有大致三种解决方案。

### 仅忽略当前仓库

在 `.gitignore` 文件中增加下面内容：

```gitignore
.DS_Store
**/.DS_Store
.DS_Store?
```

### 全局忽略

1. 打开终端，新键一个 `.gitignore_global` 用来记录所有的全局忽略文件
   ```shell
   touch ~/.gitignore_global
   ```
2. 修改这个文件，输入和上一个示例一样的内容
3. 对 Git 进行全局配置
   ```shell
   git config --global core.excludesfile ~/.gitignore_global
   ```
4. 在命令行输入 `git config --list` 检查 `core.excludesfiles` 选项是否记录了这个文件。

### 批量删除已有的 `.DS_Store`

在当前仓库目录中，输入命令
```shell
find . -name .DS_Store -print0 | xargs -0 git rm -f --ignore-unmatch
```
随后再次提交即可。

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) .DS_Store - Wikipedia <https://en.wikipedia.org/wiki/.DS_Store>

<a name="ref2">\[2\]</a>[^](#rref2) git - .gitignore all the .DS_Store files in every folder and subfolder - Stack Overflow <https://stackoverflow.com/questions/18393498/gitignore-all-the-ds-store-files-in-every-folder-and-subfolder>

