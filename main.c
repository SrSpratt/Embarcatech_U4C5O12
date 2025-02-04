#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <stdio.h>

#define LIGHTS 3

int main(){

    Pins pins[LIGHTS] = {
        {
            .Pin = REDLIGHT,
            .Input = false
        },
        {
            .Pin = YELLOWLIGHT,
            .Input = false
        },
        {
            .Pin = YELLOWLIGHT,
            .Input = false
        },

    };

    Configuration(pins, LIGHTS);

    printf("Olá");
}