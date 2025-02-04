#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <stdio.h>

#define LIGHTS 3

int main(){

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
    
    Configuration(pins, LIGHTS);
    
    // if (stdio_usb_connected())
    //     gpio_put(REDLIGHT, 1);
    // sleep_ms(1000);
    // gpio_put(REDLIGHT, 0);
    // sleep_ms(1000);

    //TestLEDs(pins, LIGHTS, 500); 

    FireInOrder(pins, LIGHTS, 3000, 0);

    uint32_t seconds = 0;

    char plural; 

    while(1){
        seconds = to_ms_since_boot(get_absolute_time()) / 1000;

        plural = seconds > 1 ? 's' : ' ';

        printf("%ld segundo%c passado%c -> Loop do Semáforo! - Aplicação funcionando!\n",  seconds, plural, plural);
        sleep_ms(1000);
    }
}