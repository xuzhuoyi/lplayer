LPlayer 
==========
LPlayer 是一个用 Qt 编写的网络视频播放器，支持在线解析播放 Acfun 的视频。LPlayer 基于 MoonPlayer，以 mplayer/mplayer2 为后端，确保了播放的稳定性。 
LPlayer 支持本地和网络视频播放，因为以 mplayer 为后端，LPlayer 支持几乎所有的视频格式。使用 NVIDIA 显示卡的用户可以在软件中开起 vdpau 硬件解码。而其他用户可以开启 vaapi 来实现硬件解码，充分发挥设备的性能

Latest version: v2.9 (2015.09.02)


安装方法
====
 
前往 Github Release 下载编译好的软件包

https://github.com/xuzhuoyi/lplayer/releases

或者自行编译

https://github.com/xuzhuoyi/lplayer

Linux (Ubuntu): 
使用 ppa: xuzy/lde 再安装 lplayer 包
Linux (Fedora): 
先开启 RPM Fusion 源
再使用 copr 源
dnf copr enable lde/lde
dnf update
dnf install lplayer  
 

