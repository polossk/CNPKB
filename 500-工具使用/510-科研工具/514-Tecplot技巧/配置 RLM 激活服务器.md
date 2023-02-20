# 配置 RLM 激活服务器

> tags: #macOS; #Linux; #CentOS; #RLM; #Tecplot;

## TL; DR

* 下载全平台的 Tecplot 安装包（目前可用的有 2020R2 与 2021R1 两版）
* 将激活服务器上传至服务器，并按照步骤解压安装
* 手动开启服务器并开放远程主机对应端口

## 详细流程

### 起因

由于目前使用的 MacBook 的 CPU 架构发生变化，原有的激活服务器脚本在执行时会因平台问题发生运行错误，因此试着将激活服务器放置在阿里云的远程主机上，这样只要能链接外网就可以自由使用 Tecplot 软件绘图。

目前放出的 Tecplot 版本已经不再支持 macOS，全平台的只能找到 2020R2 与 2021R1 两版。上述版本仍然使用 RLM 服务器激活。更新的版本已经变更为重新打包的 exe 文件激活。故选择 2020R2 与 2021R1 两版中较新的 2021R1 版本作为最终选项。

### 配置流程

1. 修改 `host` 文件，屏蔽 `download.tecplot.com`
   ```plain
   127.0.0.1 download.tecplot.com
   ```
2. 解压两个压缩包，并且将 `Module_Tecplot` 压缩包中的 `Vendors` 文件夹中内容移动至 `Core` 解压后的目录当中
3. 执行 `install_or_update.sh` 脚本，会提示设置了新的服务 `/etc/systemd/system/rlmsrvssq.service`
4. 检查该服务的内容，提取出执行命令
   ```shell
   cat /etc/systemd/system/rlmsrvssq.service | grep ExecStart
   # => ExecStart=/root/tmp/Bin/rlm -c /root/tmp/Licenses/rlm_SSQ.lic -dlog /root/tmp/Logs/rlm.log -nows -noudp
   ```
5. 复制该命令，并运行，随后检查日志文件 `/root/tmp/Logs/rlm.log`，获得真实激活服务器的端口（如下面所示的 `13579` 端口）
   ```shell
   cat /root/tmp/Logs/rlm.log | grep "ISV server"
   # => 02/20 20:55 (rlm) Starting ISV server teclmd on port 13579
   ```
6. 同时开放软件要求的 `26800` 端口与真实激活服务器的端口 `13579`（样例）
7. 激活时填写服务器域名或 IP 地址，端口填写真实端口 `13579`
8. （可选）一般真实激活服务器的端口是无规律数字，如果有必要可以通过端口转发的方式映射至其他端口，如下面的命令将端口 `18888` 的 TCP 连接转发至本地的 `13579` 端口，这样可以避免每次启动服务器之后重新设置开放的端口
   ```shell
   socat TCP4-LISTEN:18888,reuseaddr,fork TCP4:0.0.0.0:13579
   ```

### 可能出现的错误

* 激活服务器的激活版本与使用版本不同，无法正常激活
* 检查端口以及远程主机的防火墙是否放行了该端口
* 检查云服务器提供商是否有额外的安全组策略，同样放行

### 日志文件样例

```plain
02/20 20:55 (rlm) RLM License Server Version 12.2BL2-p1

	Copyright (C) 2006-2017, Reprise Software, Inc. All rights reserved.

02/20 20:55 (rlm) License server started on iZ2ze48olpbvnm4l4c17lbZ
02/20 20:55 (rlm) Server architecture: x64_l1
02/20 20:55 (rlm) License files:
02/20 20:55 (rlm)     /root/tmp/Licenses/rlm_SSQ.lic
02/20 20:55 (rlm)
02/20 20:55 (rlm) Using TCP/IP port 26800
02/20 20:55 (rlm) Starting ISV server teclmd on port 13579
02/20 20:55 (teclmd) RLM License Server Version 12.2BL2-p1 for ISV "teclmd"
02/20 20:55 (teclmd) Settings from RLM Version 11.2BL2 for ISV "teclmd"
02/20 20:55 (teclmd) Server architecture: x64_l1

    Copyright (C) 2006-2017, Reprise Software, Inc. All rights reserved.

    RLM contains software developed by the OpenSSL Project
    for use in the OpenSSL Toolkit (http://www.openssl.org)
    Copyright (c) 1998-2008 The OpenSSL Project. All rights reserved.
    Copyright (c) 1995-1998 Eric Young (eay@cryptsoft.com) All rights reserved.

02/20 20:55 (teclmd)
02/20 20:55 (teclmd) Server started on iZ2ze48olpbvnm4l4c17lbZ (hostid: ANY) for:
02/20 20:55 (teclmd) 	suite rs chorus 360ex focus batch rlm_server_enable_vm

02/20 20:55 (teclmd)
02/20 20:55 (teclmd) License files:
02/20 20:55 (teclmd)     /root/tmp/Licenses/rlm_SSQ.lic
02/20 20:55 (teclmd)
```