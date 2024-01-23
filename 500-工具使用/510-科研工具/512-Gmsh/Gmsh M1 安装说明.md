# Gmsh M1 安装说明

> tags: #macOS; #M1; #Gmsh; #Homebrew;

## TL; DR

* homebrew 安装 gmsh
* 安装 python 接口库
* 通过软链接设置动态链接库

## 详细流程

1. 命令行输入 `brew install gmsh` 安装 gmsh，当前版本为 4.10.5
2. 通过 GitHub 上的已有的脚本手动安装 `gmsh.py` 接口
   ```bash
   pip install git+https://github.com/lukeolson/gmsh-python-homebrew
   ```
3. 通过软链接将动态链接库手动设置到 python 环境中
   1. 找到 brew 安装好的 gmsh 的路径，如 `/opt/homebrew/lib/`
   2. 定位到 python 的库目录的路径，如 `~/opt/anaconda3/lib/`
   3. 将 `libgmsh.*` 的库文件全部链接
   ```bash
   ln -s /opt/homebrew/lib/libgmsh.a ~/opt/anaconda3/lib/libgmsh.a
   ln -s /opt/homebrew/lib/libgmsh.dylib ~/opt/anaconda3/lib/libgmsh.dylib
   ln -s /opt/homebrew/lib/libgmsh.4.10.5.dylib ~/opt/anaconda3/lib/libgmsh.4.10.5.dylib
   ln -s /opt/homebrew/lib/libgmsh.4.10.dylib ~/opt/anaconda3/lib/libgmsh.4.10.dylib
   ```


## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) gmsh — Homebrew Formulae <https://formulae.brew.sh/formula/gmsh#default>

<a name="ref2">\[2\]</a>[^](#rref2) lukeolson/gmsh-python-homebrew: wrapping gmsh.py with a pip <https://github.com/lukeolson/gmsh-python-homebrew>
