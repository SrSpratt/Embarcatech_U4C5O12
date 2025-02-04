#include <Lights_U4C5.h>

RepeatingTimer repeatingTimer;
void FireInOrder(Pin* pins, uint8_t size, uint32_t duration, uint8_t first){
    //Insere o número de pinos no provedor global para o contador acessar mais tarde
    context.VectorSize = size;

    //Liga o primeiro pino
    gpio_put(pins[first].Pin, 1);
    //Armazena o primeiro pino no provedor global, como memória de estado
    context.TurnedOn = pins[first].Pin;
    
    //Adiciona o contador por duration milissegundos
    add_repeating_timer_ms(duration, HandleChangeLED, NULL, &repeatingTimer);

}

bool HandleChangeLED(RepeatingTimer *t){

    //Observa o LED que estava ligado na chamada para o manipulador anterior e acende o próximo
    if(context.TurnedOn == REDLIGHT){
        gpio_put(REDLIGHT, 0);
        gpio_put(GREENLIGHT, 0);
        gpio_put(YELLOWLIGHT, 1);
        //Salva o estado novo (LED ligado dessa iteração)
        context.TurnedOn = YELLOWLIGHT;
    } else if (context.TurnedOn == YELLOWLIGHT){
        gpio_put(REDLIGHT, 0);
        gpio_put(YELLOWLIGHT, 0);
        gpio_put(GREENLIGHT, 1);   
        context.TurnedOn = GREENLIGHT;
    } else {
        gpio_put(YELLOWLIGHT, 0);
        gpio_put(GREENLIGHT, 0);
        gpio_put(REDLIGHT, 1);
        context.TurnedOn = REDLIGHT;
    }

    return true;
}


void TestLEDs(Pin* pins, uint8_t size, uint32_t duration){
    for(uint8_t i = 0; i < size; i++){
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
        context.Pins[i] = pins[i];
    }


    context.VectorSize = size;

    add_alarm_in_ms(duration, HandleToggle, NULL, false);
}

int64_t HandleToggle(alarm_id_t id, void *user_data){
    PrintContext(context);
    for(uint8_t i = 0; i < context.VectorSize; i++){
        gpio_put(context.Pins[i].Pin, !gpio_get(context.Pins[i].Pin));
        //PrintPin(context.Pins[i]);
    }
    return 0;
}