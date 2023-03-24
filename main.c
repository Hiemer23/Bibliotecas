/*
 * File:   main.c
 * Author: andrey.hiemer
 *
 * Created on 21 de Março de 2023, 09:39
 */

#include "main.h"

//void pisca() {
//    if (counter == 100) {
//        LATB = ~LATB;
//        counter = 0;
//    }
//}

void __interrupt() interruptsManager(void) {

    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        TMR0 = 6;
        INTCONbits.TMR0IF = 0;
        counter_display++;
        contador++;
    }

}

void Init_Timers(void) {
    //--------------------------------------------------------------------------
    // Timer0 operando como base de tempo para o sistema
    //--------------------------------------------------------------------------
    T0CON = 0b11000011; // Timer 0 funcionando pelo oscilador com Prescaler 1:16
    TMR0IE = 1;

    PEIE = 1;

    GIE = 1;

}

void main(void) {
    //Define o método de funcionamento dos pinos para saida do PORTB
    //'0' para output e '1' para input
    TRISB = 0x00;
    TRISC = 0x00;
    //inicia a saída com tudo zero
    LATB = 0x00;
    LATC = 0x00;
    //Indica a frequência de trabalho
    OSCCON = 0b11111100; //16MHz
    Init_Timers();
    //Inicializa o timer0
    TMR0 = 6;
    //Inicializa o display
    //PonteiroDeFuncao = initialize_LCD;
    initialize_LCD();
    char timer[17];
    sprintf(timer, "Tempo: %d", contador);
    change_Message(0, timer);
    while (1) {
        if (counter_display >= 5) {
            Write_Display();
            counter_display = 0;
            *timer = '\0';
            sprintf(timer, "Tempo: %d", contador);
            change_Message(0, timer);
        }
    }
}
