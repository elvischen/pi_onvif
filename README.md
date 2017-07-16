###  Onvif在树莓派3代B型上的移植

#### 基本环境搭建
1.生成框架代码
2.制作基本静态库
3.生成onvifserver进程

#### 搜索服务实现


#### 设备管理模块实现

#### V4L2调用USB摄像头
    1.打开设备. int fd = open("/dev/video0", O_RDWR).
    2.获取设备的capability.命令VIDEOC_QUERYCAP.结构体struct v4l2_capability.
    3.设置视频的帧格式，帧的格式包括宽度和高度
    4.向驱动申请帧缓冲，一般不超过5个
    5.将申请到的帧缓冲映射到用户空间，直接操作采集到的帧
    6.开始视频的采集.命令VIDEOC_STREAMON
    7.出队列以取得采集数据的帧缓冲，取得原始采集数据.命令VIDEOC_DQBUF.
    8.将缓冲直接入队列尾，这样可以循环采集.命令VIDEOC_QBUF.
    9.停止视频采集.命令VIDEOC_STREAMOFF.
    10.关闭视频设备.close(fd)

    [与非网](http://account.eefocus.com)