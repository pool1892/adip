#include <stdio.h>


int laenge(char s[]) {
   int i=0;
   while (s[i] != '\0') i++;
   return i;
}

int palindrom(char s[]) {
   int i,l;
   l = laenge(s);
   for (i=0; i<l/2; i++) 
      if ( (s[i]) != (s[l-i-1])) 
         return(0);
   return(1);
}

int main() {
   char input[200];
printf("%s\n", "Welches Wort soll geprueft werden?" );
scanf("%s", input);

printf("%s, ok. \n", input );
printf("%s ist %d Zeichen lang.\n",input, laenge(input));
      
      if ( palindrom(input) )
         printf("%s ist ein Palindrom\n", input);
      else
         printf("%s ist kein Palindrom\n", input);
   
  return 0;
}


