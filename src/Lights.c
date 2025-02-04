#include <Lights_U4C5.h>

void TestLEDs(PinState* pins, uint8_t size, uint8_t duration){
    for(uint8_t i = 0; i < size; i++)
        gpio_put(pins[i].Pin, !pins[i].State);

    sleep_ms(duration);

    for(uint8_t i = 0; i < size; i++)
        gpio_put(pins[i].Pin, !pins[i].State);
}