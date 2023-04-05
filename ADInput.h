/* 
 * File:   ADInput.h
 * Author: andrey.hiemer
 *
 * Created on 24 de Março de 2023, 15:05
 */

#ifndef ADINPUT_H
#define	ADINPUT_H

#define Leitura_ON ADCON0bits.ADON=1
#define Leitura_OFF ADCON0bits.ADON=1
#define Convertion_ON ADCON0bits.GO=1   
#define Convertion_OFF ADCON0bits.GO=0
#define GO_BIT ADCON0bits.GO

//Prototypes

int ADC_Read();
int getMedia(void);
void TaskAD(void) ;

#endif	/* ADINPUT_H */

