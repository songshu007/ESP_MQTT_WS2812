#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>

const char ssid[] = "CMCC-ziv2";  // WIFI 名称
const char pass[] = "wb6zzwti";  // WIFI 密码

const char mqttClientId[] = "esp-color-client"; // MQTT 客户端id
const char mqttHost[] = "117.50.181.42";     // MQTT 服务器地址
const char mqttPort[] = "1883";     // MQTT 服务器端口
const char mqttUser[] = "root";     // 用户名
const char mqttPass[] = "123456";     // 密码

#define NUM_LEDS 40
#define DATA_PIN D3
CRGB leds[NUM_LEDS];

WiFiClient net;
MQTTClient client;

DynamicJsonDocument doc(1024);

//////////////////////////////// 函数声明 //////////////////////////////////////////////////
void messageReceived(String &topic, String &payload);


////////////////////////////////////////////////////////////////////////////////////////////

void ConnectMQTTServer()
{
    Serial.print("\nconnect MQTT Server...");
    while (!client.connect(mqttClientId, mqttUser, mqttPass))
    {
        Serial.print(".");
        delay(1000);
    }

    Serial.println("\nconnected!");

    client.subscribe("test/color");
}

void ConnectWIFI()
{
    WiFi.begin(ssid, pass);

    client.begin(mqttHost, net);
    client.onMessage(messageReceived);

    Serial.print("connect wifi...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
}

uint8_t R = 0;
uint8_t G = 0;
uint8_t B = 0;
uint8_t BRIGHTNESS = 0;

// 回调函数，当有消息传来时的处理
void messageReceived(String &topic, String &payload) {
    Serial.println("incoming: " + topic + " - " + payload);

    deserializeJson(doc, payload);
    JsonObject obj = doc.as<JsonObject>();

    R = obj[String("color")][0];
    G = obj[String("color")][1];
    B = obj[String("color")][2];
    BRIGHTNESS = obj[String("brightness")];
}

void setup()
{
    Serial.begin(115200);
    ConnectWIFI();
    ConnectMQTTServer();

    FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
    for (size_t i = 0; i < NUM_LEDS; i++)
        leds[i] = CRGB::Black;
    FastLED.show();
}

void loop()
{
    client.loop();
    delay(10);

    if (!client.connected())
    {
        ConnectMQTTServer();
    }

    for (size_t i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(G, R, B);
    }
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.show();
}