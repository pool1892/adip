#include "stdio.h"
int main () {
	int a, n, result=1, i;

	printf("die Basis\n");
	scanf("%d", &a);
	printf("den Exponent bitte\n");
	scanf("%d", &n);

	if (n==0) {
		result=1; }
	if (n==1) {
		result=a; }
		
	else if (n>1) {
		for(i=n-1; i>=1; i--) {
			result*=a;
		}
	result*=a;	
	}
		
	

	printf("Result \n %d\n", result);
		return 0;
}
