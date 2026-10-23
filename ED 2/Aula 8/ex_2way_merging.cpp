#include <stdio.h>
#include <stdlib.h>

int *merging(int a[], int b[]){
    int *c;
    int idx = 0;
    int i = 0;
    int j = 0;
    while(a[i] != -1 && b[j] != -1){
        if(a[i]<=b[j]){
            c[idx]=a[i];
            i++;
        }else{
            c[idx]=b[j];
            j++;
        }
        idx++;
    }
    if(a[i]==-1){
        while(b[j] != -1){
            c[idx] = b[j];
            idx++;
            j++;
        }
        c[idx] = -1;
        return (c);
    }
    if(b[j]==-1){
        while(a[i] != -1){
            c[idx] = a[i];
            idx++;
            i++;
        }
        c[idx] = -1;
        return c;
    }
}

int main(){
    int a[6] = {10, 25, 30, 45, 60, -1};
    int b[7] = {5, 20, 30 , 40, 50, 70, -1};

    int *merge = merging(a, b);

    int i = 0;
    while(merge[i] != -1){
        printf("%d  ", merge[i]);
        i++;
    }

    return 0;
}