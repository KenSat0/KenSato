#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Necessário para a função getch()

int main(){
    FILE *f = fopen("ex1.txt", "w+");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    char c = 0;

    while(1){
        c = getch();

        if(c == (0x0D)){
            c = '\n';
        }

        fputc(c, f);

        if(c == (0x1B)){
            break; 
        }

        printf("%c", c);
    }

    rewind(f); 
    printf("\n");

    int r; 
    while((r = fgetc(f)) != EOF){ 
        printf("%c", r);
    }

    fclose(f);
    return 1;
}