#include <Lights_U4C5.h>

void TestLEDs(Pin* pins, uint8_t size, uint32_t duration){
    for(uint8_t i = 0; i < size; i++)
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));

    sleep_ms(duration);

    for(uint8_t i = 0; i < size; i++)
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
}