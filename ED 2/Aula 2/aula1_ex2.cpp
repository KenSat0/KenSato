#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *f = fopen("ex2.txt", "rb");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    unsigned char buffer[16];
    int bytesLidos;
    int offset = 0;

    while((bytesLidos = fread(buffer, sizeof(unsigned char), 16, f)) > 0){
        
        printf("%02X: ", offset);

        for(int i = 0; i < bytesLidos; i++){
            printf("%02X ", buffer[i]);
        }

        for(int i = 0; i < 16; i++){
            printf("    ");
        }

        printf(" |");

        for(int i = 0; i < bytesLidos; i++){
            if(isprint(buffer[i])) printf("%c", buffer[i]);
            else printf(".");
        }

        printf("|\n");
        offset += bytesLidos;
    }

    fclose(f);
    return 1;
}