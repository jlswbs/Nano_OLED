// Simple chaotic attractor //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float x = 0.1f;
    float y = 0.0f;
    float z = 0.0f;

    float dt = 0.03f;
    float a = 0.43f;


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

        x = nx + dt * (-ny + powf(nz, 2.0f));
        y = ny + dt * (nx + a * ny);
        z = nz + dt * (nx - nz);

        int ax = 90 + (18 * x);
        int ay = 16 + (10 * y);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);

    }

    oled.displayBuffer();

}