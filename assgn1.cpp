/*Input a string from user on command line. 
String may have multiple commas e.g. "Welcome,to,Sunbeam,CDAC,Diploma,Course".
Print each word individually. Hint: use strtok() function.*/
#include<string.h>
#include<stdio.h>


int main () {
   char str[80];//= "This is,www.tutorialspoint.com,website";;
   //scanf("%10[^,]",str);
   gets(str);
   const char s[2] = ",";
   char *token;

   /* get the first token */
   token = strtok(str, s);

   /* walk through other tokens */
   while( token != NULL ) {
      printf( "%s\n", token );

      token = strtok(NULL, s);
   }

   return(0);
}

