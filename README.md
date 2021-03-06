# Arduino_Demo

## 开发板
  开发板使用的是[nodemcu-devkit-v1.0](https://github.com/nodemcu/nodemcu-devkit-v1.0)

## Arduino SDK
  SDK使用的是[Arduino core for ESP8266](https://github.com/esp8266/Arduino)

## 项目说明
  ### ir_remoter
  该示例学习红外控制，使用的库是[IRremoteESP8266](https://github.com/markszabo/IRremoteESP8266/)，使用的红外接收头为[IRM-3638T](./ir_remoter/docs/IRM-3638T_PDF_C16216_2017-06-16.PDF).

  [IRrecvDemo](./ir_remoter/IRrecvDemo) 演示了使用IRremoterESP8266库进行红外解码，红外遥控器为美的塔扇。红外接收头连接到Devkit的D5，当接收到红外按键信号时，在串口打印按键信息和红外码同时D0连接的LED闪烁一次。

  [IRrecvDumpV2](./ir_remoter/IRrecvDumpV2) 演示了使用IRremoterESP8266库进行红外解码，红外接收头连接到Devkit的D5，当接收到红外按键信号时，在串口打印红外码的波形和码值。

  ### weather_station
  [weather_station](./weather_station) 演示了一个简易WIFI气象站,从 [心知天气](https://www.seniverse.com/doc) 提供的API获取气象数据，使用到WIFI模块和 [ArduinoJson](https://github.com/bblanchon/ArduinoJson) 库，注意需要使用5.13.2版本，否则编译会不通过。获取的天气数据是JSON格式，程序对JSON数据进行解析，解析后通过串口打印天气信息。

  参考链接：[《博哥ESP8266系列2》- ESP8266 获取天气情况](https://www.arduino.cn/thread-49411-1-2.html)

  ### oled
  [test_ssd1331](./oled/test_ssd1331) 演示了使用SSD1331驱动芯片的0.96" OLED显示屏，型号为UG-9664HDDAG01。采用IO模拟SPI，BS1、BS2接GND，VDD和VDDIO由devkit模块3.3V供电，VCC由外部12V电源供电，搭的demo没有用升压电路。
  使用的SSD1331驱动库修改自[Adafruit-SSD1331-OLED-Driver-Library-for-Arduino](https://github.com/adafruit/Adafruit-SSD1331-OLED-Driver-Library-for-Arduino)和图形库[Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)。
  显示效果如下：
  ![demo1](oled/test_ssd1331/docs/demo1.jpg)
  ![demo2](oled/test_ssd1331/docs/demo2.jpg)
  ![demo3](oled/test_ssd1331/docs/demo3.jpg)