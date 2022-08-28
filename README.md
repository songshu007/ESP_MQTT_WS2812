# ESP_MQTT_WS2812

通过 MQTT 控制 WS2812 灯带，这是一个很简单的小项目

# 控制端

控制端用 QT 写的，在 `QT_ESP_MQTT_Color` 文件夹下，可以运行在 win 平台上，使用控制端时请先点击 `连接` 按钮

# 接收端

接收端用 platformio 的 Arduino 框架 写的，在 `Arduino_ESP8266_MQTT` 文件夹下，可以上传到自己喜欢的 ESP 开发板上，只需要更改一下 WIFI 名称，WIFI 密码，以及 WS2812 灯带的数据引脚

另外 MQTT 的服务器是我自己搭建的，有需要可以自己在源码中更改
