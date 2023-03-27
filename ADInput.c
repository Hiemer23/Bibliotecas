#include "main.h"

//aguardar até terminar

int ADC_Read() {
    int digital;

    /* Channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000) & ADC is disabled */
    //ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  

    Leitura_ON;
    Convertion_ON;
    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while (GO_BIT == 1);

    digital = (ADRESH * 256) | (ADRESL); /*Combine 8-bit LSB and 2-bit MSB*/
    return (digital);
}

//ler e converter