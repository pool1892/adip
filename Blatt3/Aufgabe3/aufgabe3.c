
#include <stdio.h>
void untprog1(int z){
unsigned int mask = 01 << 31;
int i;
for(i=31; i>=0; i--) {
 if  ((z&mask) !=0)
 printf("1");
 else
 printf("0");
 if((i%8==0) && mask!=1)
   printf(".");
mask >>= 1;
}
printf("\n");
}
int main(){
int input;
printf("Welche Zahl soll binär dargestellt werden?\n");
scanf("%i", &input);
printf("Die Binärdarstellung von %d ist ", input);
untprog1(input);

printf("Das Unterprogramm gibt für 3 die Zahl: ");
untprog1(3); 
printf("Das Unterprogramm gibt für 8 die Zahl: ");
untprog1(8);
printf("Das Unterprogramm gibt für 42 die Zahl: ");
untprog1(42);


return 0;
}