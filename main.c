/*
 * File:   main.c
 * Author: andrey.hiemer
 *
 * Created on 21 de Março de 2023, 09:39
 */

#include "main.h"

//Variaveis globais
int counter_5ms = 0;
int counter_50ms = 0;
int ad = 0;
unsigned int contador = 0;
char timer[17];

void __interrupt() interruptsManager(void) {

    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        TMR0 = 6;
        INTCONbits.TMR0IF = 0;
        counter_5ms++;
        counter_50ms++;
        contador++;
    }

}

void Init_Timers(void) {
    //Indica a frequência de trabalho
    OSCCON = 0b11111100; //16MHz
    OSCTUNEbits.PLLEN = 1; //define para 64MHz
    //--------------------------------------------------------------------------
    // Timer0 operando como base de tempo para o sistema
    //--------------------------------------------------------------------------
    T0CON = 0b11000101; // Timer 0 funcionando pelo oscilador com Prescaler 1:64
    TMR0IE = 1;

    PEIE = 1;

    GIE = 1;

}

inline void pinInverte(void) {

    LATC0 = ~LATC0;

}

void tempo5_ms(void) {

    counter_5ms = 0;
    Write_Display();
    pinInverte();
    ad = getMedia();
    *timer = '\0';
    sprintf(timer, "Tempo: %d", contador);
    change_Message(1, timer);
    sprintf(timer, "AD: %d", ad);
    change_Message(0, timer);

}

void main(void) {
    //Define o método de funcionamento dos pinos para saida do PORTB
    //'0' para output e '1' para input
    TRISB = 0x00;
    TRISC = 0x00;
    TRISA = 0x01; //Analog input
    //inicia a saída com tudo zero
    LATB = 0x00;
    LATC = 0x00;
    Init_Timers();
    //Inicializa o timer0
    TMR0 = 6;

    //AnalogRegisters configuration
    ADCON0 = 0b00000001;
    ADCON1 = 0b00000;
    ADCON2 = 0b10011101;

    //Inicializa o display
    initialize_LCD();

    sprintf(timer, "Tempo: %d", contador);
    change_Message(0, timer);
    while (1) {
        TaskAD();
        if (counter_5ms >= 5) {
            tempo5_ms();
        }
    }
}
