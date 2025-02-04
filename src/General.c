#include <General_U4C5.h>

void Configuration(Pin* pins, uint8_t size){
    stdio_init_all();

    for (uint8_t i = 0; i < size; i++){
        if (pins[i].Input)
            SetInput(pins[i].Pin);
        else
            SetOutput(pins[i].Pin);
    }
}

void SetInput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_down(pin);
}

void SetOutput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, 0);
}

uint8_t GetState(Pin pin) {
    if (pin.Input) {
        return -1;  // Retorna -1 como indicador de erro (para entrada)
    }
    return gpio_get(pin.Pin);
}
