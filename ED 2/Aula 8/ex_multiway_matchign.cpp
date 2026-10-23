#include <stdio.h>
#include <stdlib.h>

int *matching(int a[], int b[], int c[]){
    //assume que a <= b <= c
    int *match;
    int i = 0;
    int j = 0;
    int k = 0;
    int idx = 0;
    while(a[i] != -1 && b[j] != -1 && c[k] != -1){
        if(a[i] == b[j]){
            if(a[i] == c[k]){
                match[idx] = a[i];
                i++;
                idx++;
            } else {
                if(b[j]<c[k]){
                    j++;
                } else {
                    k++;
                }
            }
        } else {
            if(a[i] < b[j]){
                i++;
            } else {
                j++;
            }
        }
    }

    match[idx] = -1;
    return match;
}

int main(){
    int a[6] = {10, 25, 30, 45, 60, -1};
    int b[7] = {10, 25, 30, 40, 50, 70, -1};
    int c[6] = { 1,  8, 10, 18, 25, -1};

    int tam_a = sizeof(a)/sizeof(int);
    int tam_b = sizeof(b)/sizeof(int);
    int tam_c = sizeof(c)/sizeof(int);
    int *match;

    if(tam_b < tam_a || tam_c < tam_a){
        if(tam_b < tam_c){
            printf("b menor");
            match = matching(b, a, c);
        } else {
            printf("c menor");
            match = matching(c, a, b);
        }
    } else {
        printf("a menor");
        match = matching(a, b, c);
    }

    int i = 0;
    while(match[i] != -1){
        printf("%d  ", match[i]);
        i++;
    }

    return 0;
}