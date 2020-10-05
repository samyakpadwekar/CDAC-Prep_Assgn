#include<stdio.h>

void Add(int a[])
{
  int i,flag=0;
  printf("\nSelect index number at which number is to be added from the available indexes\n");
  for(i=0;i<10;i++)
  {
   if(a[i]==0)
   {
    printf("%d ",i);
    flag=1;
   }
  }
  if(flag==0)
  {
   printf("No. indexes are available to add number");
  }
  printf("\n");
  scanf("%d",&i);
  printf("\nEnter number to add at index %d\n",i);
  scanf("%d",&a[i]);
}

void Delete(int a[])
{
 int i,flag=0;
 printf("\nSelect index number at which number is to be deleted from the available indexes\n");
 for(i=0;i<10;i++)
  {
   if(a[i]!=0)
   {
    printf("index i=%d value at i=%d",i,a[i]);
    flag=1;
   }
  }
 if(flag==0)
  {
   printf("No. indexes are available for deletion");
  }
 printf("\n");
 scanf("%d",&i);
 a[i]=0;
}

void Max(int a[])
{
  int i,j,k;
  int max = a[0];

  for (i = 1; i < 10; i++)
  {
    if (a[i] > max)
    {
     max = a[i];
     j=i;
    }
    else if(a[i]==max)//if max num is at two diff indexes
     k=i;
   }
  if(j==k)
  printf("Maximum number in given array is %d at index %d",max,j);

  else
  printf("Maximum number in given array is %d at index %d and %d",max,j,k);

}

void Min(int a[])
{
 int i;
 int j=0;
 int min= a[0];
 for(i = 0; i < 10; i++)
 {
    if(min > a[i])
    {
      min= a[i];
      j= i;
    }
 }
 printf("Minimum number in given array is %d at index %d",min,j);
}

void Sum(int a[])
{
 int sum=0,i;

 for(i=0;i<10;i++)
 {
   sum=sum+a[i];
 }
}

int main()
{
 int arr[10]={};
 int i;
 int j;

 //printf("Press 1 to Continue \nPress 0 to end\n");
 //scanf("%d",&i);

 do
 {
 printf("Enter options between 1-5\n");
 printf("1.Add number at index ""i""\n");
 printf("2.Delete number at index ""i""\n");
 printf("3.Find maximum number\n");
 printf("4.Find minimum number\n");
 printf("5.Calculate summ of numbers\n");

 scanf("%d",&i);
 switch(i)
 {
  case 1: Add(arr);
          break;

  case 2: Delete(arr);
          break;

  case 3: Max(arr);
          break;

  case 4: Min(arr);
          break;

  case 5: Sum(arr);
          break;
 }

 printf("\nPress 1 to Continue \nPress 0 to end\n");
 scanf("%d",&i);

}while(i);

 return(0);
}
