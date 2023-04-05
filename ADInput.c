#include "main.h"

//Variáveis Locais
uint16_t media, soma, contador_media, div_media = 64;
int ADC_Read() {
    int digital;

    Leitura_ON;
    Convertion_ON;

    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while (GO_BIT == 1);

    digital = (ADRESH * 256) | (ADRESL); /*Combine 8-bit LSB and 2-bit MSB*/
    return (digital);
}
//ler e converter

void TaskAD(void) {
    soma += ADC_Read();
    contador_media++;
    if (contador_media>=div_media) {
        media = soma / contador_media;
        contador_media = 0;
        soma=0;
    }
}

int getMedia(void) {
    return media;
}