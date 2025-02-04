#ifndef GENERAL_U4C5_H
#define GENERAL_U4C5_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

/**
 * @brief Representa um pino e sua configuração de entrada ou saída.
 */
typedef struct PinOut {
    uint8_t Pin;  // Número do pino
    bool Input;   // Define se o pino é de entrada (true) ou saída (false)
} Pin;

/**
 * @brief Armazena o contexto do temporizador.
 */
typedef struct TimerContext {
    uint8_t TurnedOn;   // Último pino que foi ligado
    uint8_t VectorSize; // Número total de pinos armazenados
    Pin Pins[3];        // Vetor de pinos armazenados no contexto
} Context;

/**
 * @brief Contexto global do temporizador, para armazenar o estado anterior à chamada do callback.
 */
extern Context context;

/**
 * @brief Configura o monitor serial e cada pino no vetor enviado como entrada ou saída.
 *
 * @param Pin* Ponteiro para um vetor de pinos.
 * @param uint8_t Quantidade de pinos no vetor.
 */
void Configuration(Pin*, uint8_t);

/**
 * @brief Configura um pino como entrada.
 *
 * @param uint8_t Número do pino.
 */
void SetInput(uint8_t);

/**
 * @brief Configura um pino como saída.
 *
 * @param uint8_t Número do pino.
 */
void SetOutput(uint8_t);

/**
 * @brief Exibe informações de um pino.
 *
 * @param Pin Estrutura contendo as informações do pino.
 */
void PrintPin(Pin);

/**
 * @brief Exibe o contexto atual do temporizador.
 *
 * @param Context Estrutura contendo o contexto do temporizador.
 */
void PrintContext(Context);

#endif 