// Lorenz chaotic attractor //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float s = 10.0f;
    float r = 28.0f;
    float b = 8.0f / 3.0f;

    float x = 1.0f;
    float y = 1.0f;
    float z = 1.0f;

    float dt = 0.005f;

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
    
        x = nx + dt * (s * (ny - nx));
        y = ny + dt * (nx * (r - nz) - ny);
        z = nz + dt * (nx * ny - b * nz);

        int ax = 32 + (1.6f*x);
        int ay = 32 + y;
        int az = 64 - (z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64+ax, az);

    }

    oled.displayBuffer();

}