#ifndef LIGHTS_U4C5_H
#define LIGHTS_U4C5_H

#include <General_U4C5.h>  // Inclui as definições gerais dos pinos e funções

/**
 * @brief Definições dos pinos dos LEDs de sinalização.
 */
#define REDLIGHT 11      // Pino do LED vermelho 
#define YELLOWLIGHT 12   // Pino do LED amarelo 
#define GREENLIGHT 13    // Pino do LED verde 

/**
 * @brief Renomeia `struct repeating_timer` para `RepeatingTimer`.
 */
typedef struct repeating_timer RepeatingTimer;

extern RepeatingTimer repeatingTimer;

/**
 * @brief Acende os LEDs na sequência dada pela atividade.
 *
 * @param Pin* Ponteiro para um vetor de pinos.
 * @param uint8_t Quantidade de pinos no vetor.
 * @param uint32_t Duração em milissegundos antes da troca de LED.
 * @param uint8_t Índice do primeiro LED a ser aceso.
 */
void FireInOrder(Pin*, uint8_t, uint32_t, uint8_t);

/**
 * @brief Manipula a mudança do LED aceso em um ciclo repetitivo.
 *
 * @param RepeatingTimer* Ponteiro para `RepeatingTimer` (definido como `struct repeating_timer`).
 * @return true se o timer deve continuar, false caso contrário.
 */
bool HandleChangeLED(RepeatingTimer*);

/**
 * @brief Testa os LEDs invertendo seu estado por um curto período de tempo.
 *
 * @param Pin* Ponteiro para um vetor de pinos.
 * @param uint8_t Quantidade de pinos no vetor.
 * @param uint32_t Duração do teste em milissegundos.
 */
void TestLEDs(Pin*, uint8_t, uint32_t);

/**
 * @brief Manipula a inversão dos LEDs após o tempo determinado.
 *
 * @param alarm_id_t Identificador do alarme.
 * @param void* Dados adicionais passados para a função (não utilizados).
 * @return Sempre retorna 0 para indicar que o alarme não será repetido.
 */
int64_t HandleToggle(alarm_id_t, void*);

#endif