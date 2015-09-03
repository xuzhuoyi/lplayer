LPlayer
==========
LPlayer 是一个用 Qt 编写的网络视频播放器，支持在线解析播放 Acfun 的视频。LPlayer 基于 MoonPlayer，以 mplayer/mplayer2 为后端，确保了播放的稳定性。
LPlayer 支持本地和网络视频播放，因为以 mplayer 为后端，LPlayer 支持几乎所有的视频格式。使用 NVIDIA 显示卡的用户可以在软件中开起 vdpau 硬件解码。而其他用户可以开启 vaapi 来实现硬件解码，充分发挥设备的性能

Latest version: v2.9 (2015.09.02)

编译运行依赖
====
* pkg-config
* qtbase5-dev
* qt5-qmake
* libqt5network5
* python-dev
* libqt5xml5
* libqt5webkit5-dev
* libqt5dbus5
* cmake
* mplayer
* python3
* git

在不同发行版中，以上包可能会有不同名称

编译方法
====
1.下载代码库
```bash
git clone https://github.com/xuzhuoyi/lplayer
```
2.进入目录
```bash
cd lplayer
```
3.初始化子模块
```bash
git submodule init
```
4.下载子模块
```bash
git submodule update
```
5.生成 Makefile
```bash
cmake .
```
6.编译
```bash
make
```
7.安装
```bash
sudo make install
```

已编译好的包
====

您也可以前往 Github Release 下载编译好的软件包

https://github.com/xuzhuoyi/lplayer/releases

使用源安装
====
Linux (Ubuntu):

使用 ppa: xuzy/lde 再安装 lplayer 包

Linux (Fedora):

先开启 RPM Fusion 源

再使用 copr 源
```bash
dnf copr enable lde/lde
dnf update
dnf install lplayer  
```
