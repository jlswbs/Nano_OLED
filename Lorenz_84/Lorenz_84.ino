// Lorenz 84 chaotic attractor //

#include "SSD1306.h"

OLED oled(WIDTH_128, HEIGHT_64);

    float a = 1.111f;
    float b = 1.479f;
    float f = 4.494f;
    float g = 0.44f;

    float x = 1.0f;
    float y = 1.0f;
    float z = 1.0f;

    float dt = 0.1235f;

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
    
        x = nx + dt * (-a * nx - powf(ny, 2.0f) - powf(nz, 2.0f) + a * f);
        y = ny + dt * (-ny + nx * ny - b * nx * nz + g);
        z = nz + dt * (-nz + b * nx * ny + nx * nz);

        int ax = 28 + (16 * x);
        int ay = 32 + (9 * y);
        int az = 36 - (9 * z);

        if (ax == 32) digitalWrite(LED_BUILTIN, HIGH);
        else digitalWrite(LED_BUILTIN, LOW);

        oled.drawPixel(ax, ay);
        oled.drawPixel(64 + ay, az);

    }

    oled.displayBuffer();

}