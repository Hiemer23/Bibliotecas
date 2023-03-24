////#include "main.h"
//
//void *concat(char *s1, const char*s2) {
//    //Pointer should not null pointer
//    if ((s1 == 0) && (s2 == 0))
//        return 0;
//    //Create copy of s1
//    char *start = s1;
//    //Find the end of the destination string
//    while (*start != '\0') {
//        start++;
//    }
//    //Now append the source string characters
//    //until not get null character of s2
//    while (*s2 != '\0') {
//        *start++ = *s2++;
//    }
//    //Append null character in the last
//    *start = '\0';
//    return s1;
//}
//
//char int_to_bit(int num) {
//    char c = num + '0';
//    return c;
//}
//
//void itoa(int source,char *destiny) {
//    int n = source, tamanho = 0, ultimo = 0;
//    char *s1;
//    while (n != 0) {
//        tamanho++;
//        n /= 10;
//    }
//    for (int i = 0; i < tamanho; i++) {
//        ultimo = source % 10;
//        source /= 10;
//        destiny[tamanho - (i + 1)]= ultimo+'0';
//    }
//    destiny[tamanho]='\0';
//}