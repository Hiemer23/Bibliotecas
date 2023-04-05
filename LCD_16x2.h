/* 
 * File:   LCD_16x2.h
 * Author: andrey.hiemer
 *
 * Created on 22 de Março de 2023, 09:51
 */

#ifndef LCD_16X2_H
#define	LCD_16X2_H

#define LCD_delay_ms __delay_ms
#define LCD_delay_us __delay_us
#define RS_HIGH (LATC4=1)
#define RS_LOW  (LATC4=0)
#define EN_HIGH (LATC5=1)
#define EN_LOW  (LATC5=0)
#define DB0_HIGH (LATB0=1)
#define DB0_LOW  (LATB0=0)
#define DB1_HIGH (LATB1=1)
#define DB1_LOW  (LATB1=0)
#define DB2_HIGH (LATB2=1)
#define DB2_LOW  (LATB2=0)
#define DB3_HIGH (LATB3=1)
#define DB3_LOW  (LATB3=0)
#define DB4_HIGH (LATB4=1)
#define DB4_LOW  (LATB4=0)
#define DB5_HIGH (LATB5=1)
#define DB5_LOW  (LATB5=0)
#define DB6_HIGH (LATB6=1)
#define DB6_LOW  (LATB6=0)
#define DB7_HIGH (LATB7=1)
#define DB7_LOW  (LATB7=0)

//Prototypes:

void Write_Display(void);
void initialize_LCD(void);
void change_Message(char line, char *new_Text);

#endif	/* LCD_16X2_H */

