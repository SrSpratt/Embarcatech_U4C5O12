# Embarcatech_U4C5O12-1
## Unidade 4 - Capítulo 5  
### TAREFA 2 PARTE 1 SEMÁFORO - U4C5O12 
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

#### Vídeo de funcionamento
##### No simulador wokwi:
* https://youtu.be/LA3bWfm-UcA
##### Na placa BitDogLab:
* https://youtu.be/aFynXeDv1js
    * Obs.: como é explicado no vídeo, a implementação na placa é um pouco diferente do wokwi, sendo necessários dois leds acesos no segundo estágio do semáforo para ligar a cor amarela. Executei de duas formas, primeiro com o RGB azul no lugar do amarelo, e depois fazendo a modificação para que a luz fique amarela no segundo estágio do semáforo. O código deste repositório, porém, está de acordo com o Wokwi.
    * Obs. II: as saídas em série são ilustradas através de uma conexão que abri com node.js, como mostrado no vídeo.

#### Instruções de compilação
Certifique-se de que você tem o ambiente configurado conforme abaixo:
* Pico SDK instalado e configurado.
* VSCode com todas as extensões configuradas, CMake e Make instalados.
* Clone o repositório e abra a pasta do projeto, a extensão Pi Pico criará a pasta build
* Clique em Compile na barra inferior, do lado direito (ao lado esquerdo de RUN | PICO SDK)
* Clique em diagram.json
* Dê play

#### Manual do programa
Ao executar o programa, os LEDs serão acesos na seguinte ordem:
* Primeiro será aceso o LED vermelho, por 3 segundos
* Em seguida, será aceso o LED amarelo, por mais 3 segundos
* Por fim, será aceso o LED verde, também por 3 segundos
A função de timer chamada para realizar essa sequência garante que isso ficará rodando ad infinitum nessa ordem (lógica implementada no callback da função).

* Obs.: documentei todo o código com doxygen, então ao passar o cursos do mouse em cima de qualquer uma das funções, será mostrada uma pequena descrição da implementação.
