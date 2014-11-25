#include <stdio.h>


int main(){
	int a,n;
	printf("Welche Zahl soll verwendet werden?\n");
	scanf("%d",&a);
	printf("Welcher Exponent?");
	scanf("%d",&n);

	printf("Iterativ ergibt sich %d\n", iter(a,n));
	printf("Rekursiv hingegen %d\n", rek(a,n));
	return 0;



}


int iter(int x, int y){
	int j=1;
if (y==0) return 1;
else {for (int i=1; i<=y; i++ ){j=j*x;};}
return j;
}

int rek(a, n){

if (n==0)
	return 1;
else if (n%2==0) return(rek(a, n/2)*rek(a, n/2));
else return(a*rek(a,(n-1)/2)*rek(a,(n-1)/2));
}