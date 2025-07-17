// Rossler chaotic attractor //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float x = 0.1f;
    float y = 0.1f;
    float z = 0.1f;

    float dt = 0.02f;

    float a = 0.2f;
    float b = 0.2f;
    float c = 14.0f;

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);

    oled.begin();
    oled.clearScr();

}

void loop(){

    oled.clearBuffer();

    for (int i = 0; i < 1000; i++) {

        float nx = x;
        float ny = y;
        float nz = z;
    
        x = nx + dt * (-ny - nz);
        y = ny + dt * (nx + a * ny);
        z = nz + dt * (b + nz * (nx - c));  

        int ax = 32 + x;
        int ay = 40 + y;
        int az = 64 - (0.4f * z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64 + ax, az);

    }

    oled.displayBuffer();

}