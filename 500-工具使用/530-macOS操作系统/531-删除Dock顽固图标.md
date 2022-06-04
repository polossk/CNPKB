# 删除 Dock 顽固图标

> tags: #macOS; #Dock

> **TL; DR**: 命令行内通过 `sqlite3` 从数据库中删除对应软件条目即可

1. Finder 内前往文件夹 `/private/var/folders/`
2. 在当前文件夹内搜索 `com.apple.dock.lauchpad` 文件夹并打开
3. 选择 `db` 文件夹，通过命令行打开（`cd` + 拖动文件夹进入命令行内获得具体路径）
4. 将命令中 `APP_NAME` 替换为具体应用并执行
	```zsh
	sqlite3 db "delete from apps where title='APP_NAME';"
	```
5. 关闭 Dock 应用（`killall Dock`）
