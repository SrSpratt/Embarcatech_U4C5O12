#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <stdio.h>

#define LIGHTS 3

int main(){

    //Estrutura que armazena os pinos e os estados, para facilitar a configuração
    Pin pins[LIGHTS] = {
        {
            .Pin = REDLIGHT,
            .Input = false
        },
        {
            .Pin = YELLOWLIGHT,
            .Input = false
        },
        {
            .Pin = GREENLIGHT,
            .Input = false
        },

    };
    
    //Função que recebe um vetor da estrutura Pin e configura cada pino de acordo com o Input informado, configura também o monitor serial
    Configuration(pins, LIGHTS);
    
    // if (stdio_usb_connected())
    //     gpio_put(REDLIGHT, 1);
    // sleep_ms(1000);
    // gpio_put(REDLIGHT, 0);
    // sleep_ms(1000);

    //TestLEDs(pins, LIGHTS, 500); 

    //Função com o contador que liga cada LED na ordem com um intervalo de 3s
    FireInOrder(pins, LIGHTS, 3000, 0);

    uint32_t seconds = 0;

    char plural; 

    while(1){
        //Captura o tempo passado em milissegundos e converte para segundos
        seconds = to_ms_since_boot(get_absolute_time()) / 1000;

        //verifica se é tem 0 ou 1s ou vários segundos
        plural = seconds > 1 ? 's' : ' ';

        //Imprime na tela a cada segundo a mensagem Loop do Semáforo e os segundos passados
        printf("%ld segundo%c passado%c -> Loop do Semáforo! - Aplicação funcionando!\n",  seconds, plural, plural);
        sleep_ms(1000);
    }
}