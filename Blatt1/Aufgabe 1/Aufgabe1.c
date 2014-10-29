#include "stdio.h"
int main () {
    int n, i, anz=0;
    printf("Zahl eingeben:\n");
    scanf("%d", &i);
    for(n=2; n<=i; n++) {
        while(i%n==0){
            if (anz==0) {
                printf("%d", n);
            }
            else {
                printf("*%d", n);
            } 
        anz++;
        i/=n;
        }
    }
    return 0;
}
