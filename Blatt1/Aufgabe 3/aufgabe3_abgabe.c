#include <stdio.h>

void prim(int n){
	if (0 > n) printf("ERROR: Zahl ist negativ\n");
	else{
		int m=0;
		for(m=2; m<=n/2; m++){
			if(n%m == 0){
				printf("Nein\n");
				return;
			}
		}
		printf("Ja\n");
	}
}

int main() {
	prim(10);
	return 0;
}
