// Jerk chaotic system //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float a = 0.00000001f;
    float b = 0.026f;
    
    float x = 0.1f;
    float y = 0.1f;
    float z = 0.1f;

    float dt = 0.012f; 


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

        x = nx + dt * (ny);
        y = ny + dt * (nz);
        z = nz + dt * (-nz - nx - a * (expf(ny / b) - 1.0f));

        int ax = 44 + (24 * x);
        int ay = 40 + (28 * y);
        int az = 40 + (24 * z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64+ax, az);

    }

    oled.displayBuffer();

}