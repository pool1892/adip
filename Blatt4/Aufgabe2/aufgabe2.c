#include <stdio.h>



int main(void){
	long long n,k;
	printf("Welches n?\n");
scanf("%lld",&n);
	printf("Welches k?\n");
scanf("%lld",&k);




printf("Die Fakultät von %lld ist %lld\n",n, fakultaet(n) );
printf("Es gibt %lld Möglichkeiten, %lld aus %lld zu ziehen\n", biko(n,k), k, n);
printf("Es lassen sich %lld Items auf %lld Weisen aus %lld Zahlen ziehen \n",k, fakultaet(k)*biko(n,k), n );
	return 0;
}


long long int fakultaet(long long a){
if (a==1) {return a;}
else {a=a*fakultaet(a-1);
return a;}
}

long long int biko (long long n, long long k){
long long z=1;
if (n<k) return 0;

else for ( int i=n; i>(n-k);i--) {z=z*i;};
return z/ fakultaet(k);


}