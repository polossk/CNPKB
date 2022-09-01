# 清理 macOS 图标缓存

> tags: #macOS; #Dock; #Finder

> **TL; DR**: 命令行内删除对应缓存目录即可

1. 命令行内输入命令清理 Dock 与 Finder 的图标缓存
	```shell
	sudo find /private/var/folders/ \( -name com.apple.dock.iconcache -or -name com.apple.iconservices \) -exec rm -rfv {} \;
	```
2. 命令行内输入命令清理图标缓存
	```shell
	sudo rm -rf /Library/Caches/com.apple.iconservices.store
	```
3. 关闭 Dock 应用（`killall Dock`）
4. 关闭 Finder 应用（`killall Finder`）
5. 关闭之后会自动重建所有图标缓存
