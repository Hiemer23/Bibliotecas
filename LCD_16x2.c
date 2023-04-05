#include "main.h"

//Prototypes:
void LCD_Manager();
void register_EN(void);
void initialize_LCD(void);
void function_Set(void);
void display_Off(void);
void clear_Display(void);
void entry_mode_Set(void);
void display_On(void);
void Write_Display(void);
void Write_caracter(char c);
void Set_Line(char line);
void registra_RS(void);
void change_Message(char line, char *new_Text);

//Variaveis Locais
unsigned int status_LCD_startup = 1;
char message[2][17] = {"Bem Vindo 57 123", "LCD ao Vindo Bem"};
unsigned int position_String = 0;
char linha_LCD = 0;

void register_EN(void) {
    EN_HIGH;
    LCD_delay_us(1);
    EN_LOW;
    LCD_delay_us(40);
}

void initialize_LCD(void) {
    LCD_delay_ms(16); //15ms
    function_Set();
    LCD_delay_ms(5); //4.1 ms
    function_Set();
    LCD_delay_ms(100); //100 usegundos
    function_Set();
    function_Set();
    display_Off();
    clear_Display(); //demora 2 ms essa função
    entry_mode_Set();
    display_On();
}

void function_Set(void) {
    RS_LOW;
    DB7_LOW;
    DB6_LOW;
    DB5_HIGH;
    DB4_HIGH;
    DB3_HIGH;
    DB2_LOW;
    DB1_LOW;
    DB0_LOW;
    register_EN();
}

void clear_Display(void) {
    RS_LOW;
    DB7_LOW;
    DB6_LOW;
    DB5_LOW;
    DB4_LOW;
    DB3_LOW;
    DB2_LOW;
    DB1_LOW;
    DB0_HIGH;
    register_EN();
    LCD_delay_us(1500);
}

void display_Off(void) {
    RS_LOW;
    DB7_LOW;
    DB6_LOW;
    DB5_LOW;
    DB4_LOW;
    DB3_HIGH;
    DB2_LOW;
    DB1_LOW;
    DB0_LOW;
    register_EN();
}

void display_On(void) {
    RS_LOW;
    DB7_LOW;
    DB6_LOW;
    DB5_LOW;
    DB4_LOW;
    DB3_HIGH;
    DB2_HIGH;
    DB1_HIGH;
    DB0_HIGH;
    register_EN();
}

void entry_mode_Set(void) {
    RS_LOW;
    DB7_LOW;
    DB6_LOW;
    DB5_LOW;
    DB4_LOW;
    DB3_LOW;
    DB2_HIGH;
    DB1_HIGH;
    DB0_LOW;
    register_EN();
}

void Write_Display() {

    if (position_String < 16) {
        Write_caracter(message[linha_LCD][position_String]);
        position_String++;
    } else {
        position_String = 0;
        (linha_LCD == 0) ? (linha_LCD = 1) : (linha_LCD = 0);
        Set_Line(linha_LCD);
    }

}

void Write_caracter(char c) {
    ((c >> 7)&(0x01)) ? DB7_HIGH : DB7_LOW;
    ((c >> 6)&(0x01)) ? DB6_HIGH : DB6_LOW;
    ((c >> 5)&(0x01)) ? DB5_HIGH : DB5_LOW;
    ((c >> 4)&(0x01)) ? DB4_HIGH : DB4_LOW;
    ((c >> 3)&(0x01)) ? DB3_HIGH : DB3_LOW;
    ((c >> 2)&(0x01)) ? DB2_HIGH : DB2_LOW;
    ((c >> 1)&(0x01)) ? DB1_HIGH : DB1_LOW;
    ((c >> 0)&(0x01)) ? DB0_HIGH : DB0_LOW;
    registra_RS();
}

void registra_RS(void) {
    RS_HIGH;
    LCD_delay_us(1);
    EN_HIGH;
    LCD_delay_us(1);
    EN_LOW;
    LCD_delay_us(1);
    RS_LOW;
}

void Set_Line(char line) {
    if (line == 0) {
        RS_LOW;
        DB7_HIGH;
        DB6_LOW;
        DB5_LOW;
        DB4_LOW;
        DB3_LOW;
        DB2_LOW;
        DB1_LOW;
        DB0_LOW;
        register_EN();
        return;
    }
    RS_LOW;
    DB7_HIGH;
    DB6_HIGH;
    DB5_LOW;
    DB4_LOW;
    DB3_LOW;
    DB2_LOW;
    DB1_LOW;
    DB0_LOW;
    register_EN();
}

void change_Message(char line, char *new_Text) {
    int i = 0;
    //Verifica onde acaba a string enviada
    while (new_Text[i] != '\0' && i < 16) {

        if (message[line][i] != new_Text[i]) {
                message[line][i] = new_Text[i];
            }
        i++;
    }
    for (i = i; i < 16; i++) {
        message[line][i] = ' ';
    }
}