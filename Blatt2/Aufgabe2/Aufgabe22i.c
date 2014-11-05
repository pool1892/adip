#include "stdio.h"
int main () {

	int n, a, result=1, i;

	printf("die Basis\n");
	scanf("%d", &a);
	printf("den Exponent bitte\n");
	scanf("%d", &n);

	if (n==0) {result=1;}
	if (n==1) {result=a;}


	else { 
		if (n%2==0) {
			for (i=(n/2); i>=1; i--) {
						result*=(a*a);
			}
		}
		else { 
			for(i=((n-1)/2); i>=1; i--) {
				result*=(a*a);

			}
		result*=a;

		} 
	}


	printf("Result:\n%d\n", result);
	return 0;

}
