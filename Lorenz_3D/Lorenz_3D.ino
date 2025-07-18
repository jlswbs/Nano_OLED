// Lorenz 3D chaotic map //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float x = 0.5f;
    float y = 0.5f;
    float z = -1.0f;

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
  
        x = nx * ny - nz;
        y = nx;
        z = ny; 

        int ax = 32 + (18 * x);
        int ay = 32 + (24 * y);
        int az = 32 + (24 * z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64 + ax, az);

    }

    oled.displayBuffer();

}