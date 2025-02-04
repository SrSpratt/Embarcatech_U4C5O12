#include <General_U4C5.h>

Context context;

void Configuration(Pin* pins, uint8_t size){
    //configura o monitor serial
    stdio_init_all();

    //configura cada pino do vetor de acordo com o Input informado dentro de Pin
    for (uint8_t i = 0; i < size; i++){
        if (pins[i].Input)
            SetInput(pins[i].Pin);
        else
            SetOutput(pins[i].Pin);
    }
}
//configura entrada
void SetInput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_down(pin);
}
//configura saída
void SetOutput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, 0);
}
//imprime o Pin como debugger
void PrintPin(Pin pin){
    printf("Pin ====\n");
    printf("Pin: %d\n", pin.Pin);
    printf("Input?: %d\n", pin.Input);
    printf("\n");
}
//Imprime o provedor global como debugger
void PrintContext(Context context){
    printf("Context ====\n");
    printf("Vector: %d\n", context.VectorSize);
    printf("LastState: %d\n", context.TurnedOn);
    for (uint8_t i = 0; i < context.VectorSize; i++){
        PrintPin(context.Pins[i]);
    }
    
}
