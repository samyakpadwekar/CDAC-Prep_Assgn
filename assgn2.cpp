/*2. Simulate string library functions strcpy, strcat, strcmp and strrev. */

#include<stdio.h>
#include<string.h>

char* xstrcpy(char* dest,const char* src)
{
  if(dest==NULL)
  return NULL;

  char *temp=dest;

  while(*src!='\0')
  *dest++=*src++;

  *dest='\0';

  return temp;
}

char* xstrcat(char* dest, const char* src)
{

	char* temp = dest + strlen(dest);

	while (*src != '\0')
		*temp++ = *src++;


	*temp = '\0';


	return dest;
}

int xstrcmp(const char* X,const char* Y)
{
  while(*X)
	{
      if (*X != *Y)
        break;

        X++;
		Y++;
	}

   return *(const unsigned char*)X - *(const unsigned char*)Y;
}
char* xstrrev(char X[])
{
  int j,i=strlen(X);
  //printf("\n%d",i);
  char temp;

  for(j = 0; j <i/2; j++)
    {
        temp = X[j];
        X[j]=X[i - 1 - j];
        X[i - 1 - j] = temp;
    }
  return X;
}
int main()
{
 char str[] ="Samyak";
 char str1[]="Tamyak";
 char str2[20];
 int r;

 //User-defined function for strcpy
 printf("%s\n",xstrcpy(str2,str));

 //User-defined function for strcat
 printf("%s\n",xstrcat(str2,str1));

 //User-defined function for strcmp
 r=xstrcmp(str,str1);
 if (r > 0)
    printf("%s", "X is greater than Y");
 else if (r < 0)
    printf("%s", "X is less than Y");
 else
    printf("%s", "X is equal to Y");

 //User-defined function for strrev
 printf("\n%s",xstrrev(str));

 return(0);
}
