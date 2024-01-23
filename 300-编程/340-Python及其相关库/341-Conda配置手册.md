# Conda 配置手册

> tags: #Python; #Conda; #TUNA; #Configration-Manual;

Anaconda <a name="rref1"></a>\[[1](#ref1)\] 是一个集成了绝大多数与科学计算相关的第三方库的一个 Python 发行版本。底层通过 conda 来进行虚拟环境控制，可以实现不同 Python 版本与不同库之间的相互隔离与独立维护，从而简化了后期的管理与部署操作。除了最常用的科学计算库 numpy，scipy，matplotlib 之外，同时安装了 Jupyter Notebook，Spyder，Anaconda Navigator 等相关工具。

## 安装与卸载

### 下载安装

* 从官网 <a name="rref1"></a>\[[1](#ref1)\] 中直接下载对应操作系统的安装包。
* 按照官网的说明文档 <a name="rref2"></a>\[[2](#ref2)\] 一路 Next 安装即可。
* 如果官网的连接性不佳，可以从清华大学的镜像站 <a name="rref3"></a>\[[3](#ref3)\] 中下载对应版本。

### 卸载

文档<a name="rref4"></a>\[[4](#ref4)\]中提供了两种卸载方式，个人推荐后者

* 方案A：直接删除所有文件。
    * macOS 的安装目录可能在 `~/opt` 或 `/opt` 中，直接删除掉相关目录即可，如 `rm -rf ~/anaconda3`。
* 方案B：安装 `anaconda-clean`，然后删除所有文件。
    * `conda install anaconda-clean` 安装清理工具；
    * `anaconda-clean` 执行这个工具，并且按需求输入 `[y]es` 或 `[n]o`，也可以直接默认全部卸载 `anaconda-clean --yes`；
    * 删除其他文件夹和备份文件夹即可。

## 配置源

### Conda 配置

* 直接修改用户目录下的 `.condarc` 文件即可。如果没有找到该文件，可先执行 `conda config --set show_channel_urls yes` 生成该文件之后再修改。
* 在文件中复制粘贴下面内容
    ```
    channels:
      - defaults
    show_channel_urls: true
    default_channels:
      - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
      - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/r
      - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/msys2
    custom_channels:
      conda-forge: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      msys2: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      bioconda: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      menpo: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      pytorch: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      pytorch-lts: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
      simpleitk: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
    ```
* 运行 `conda clean -i` 清除索引缓存，保证用的是镜像站提供的索引。

### PyPI 配置

* 临时使用可以通过 `-i` 来指定镜像源，注意，`simple` 不能少, 是 `https` 而不是 `http`
    ```
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple some-package
    ```
* 若需要设为默认镜像源，需要事先升级 pip 到最新的版本 (>=10.0.0) 后进行配置
    ```
    python -m pip install --upgrade pip
    pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
    ```
* 如果您到 pip 默认源的网络连接较差，临时使用镜像站来升级 pip
    ```
    python -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip
    ```

## 更新

* `conda update conda`：更新 Conda 版本
* `conda update anaconda`：更新 Anaconda 版本
* `conda update --all`：更新全部包

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Anaconda 官方网站 <https://www.anaconda.com/>

<a name="ref2">\[2\]</a>[^](#rref2) Installation - Anaconda 官方文档 <https://docs.anaconda.com/anaconda/install/>

<a name="ref3">\[3\]</a>[^](#rref3) anaconda | 镜像站使用帮助 | 清华大学开源软件镜像站 <https://mirrors.tuna.tsinghua.edu.cn/help/anaconda/>

<a name="ref4">\[4\]</a>[^](#rref4) Uninstallation Anaconda - Anaconda 官方文档 <https://docs.anaconda.com/anaconda/install/uninstall/>
