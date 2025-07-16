// Chua chaotic oscillator //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float x = 0.5f;
    float y = 0.25f;
    float z = 0.125f;

    float dt = 0.014f;

    float alpha = 15.6f;
    float beta = 28.58f;
    float a = -1.14286f;
    float b = -0.714286f;

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
    
        float h = (b * x) + (0.5f * (a - b) * (fabs(1.0f + x) - fabs(1.0f - x)));
    
        x = nx + dt * (alpha * (ny - nx - h));
        y = ny + dt * (nx - ny + nz);
        z = nz + dt * (-beta * ny);

        int ax = 32 + (12*x);
        int ay = 32 + (56*y);
        int az = 32 + (7*z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64+az, ay);

    }

    oled.displayBuffer();

}