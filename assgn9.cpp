/*An inventory management system needs to manage data of the items into binary file. 
Each item has id, name, price and quantity. 
Write a menu-driven program to implement add, find,
display all, edit and delete operations from the items file. 
Order id (int) should be generated automatically and must be unique.*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define BFILE "assgn9.bin"

typedef struct Item
{
   int id;
   char name[20];
   int price;
   int quantity;
}Item;

int get_next_id() {
	FILE *fp;
	int max = 0;
	int size = sizeof(Item);
	Item t;
	// open the file
	fp = fopen(BFILE, "rb");
	if(fp == NULL)
		return max + 1;
	// change file pos to the last record
	fseek(fp, -size, SEEK_END);
	// read the record from the file
	if(fread(&t, size, 1, fp) > 0)
		// if read is successful, get max (its) id
		max = t.id;
	// close the file
	fclose(fp);
	// return max + 1
	return max + 1;
}

void Add()
{
 FILE *fh;

 Item item;


/*opening binary file in appending / writing mode*/
 fh=fopen(BFILE,"ab");
 if(fh == NULL) {
		perror("failed to open users file");
		return;
	}

 printf("\nEnter Item Info\n");
 //printf("Item Id:");
 int i= get_next_id();
 item.id=i;
 getchar();

 printf("Name:");
 gets(item.name);

 printf("Price:");
 scanf("%d",&item.price);

 printf("Quantity:");
 scanf("%d",&item.quantity);

 fwrite(&item,sizeof(item),1,fh);

 printf("\nRecord has been added successfully");
 fclose(fh);
}

void Display()
{
FILE *fh;

Item item;
int i,found=0;

/*open binary file in read mode*/
fh=fopen(BFILE,"rb");
if(fh==NULL)
{
printf("File could not open");
exit(0);
}

printf("\nRecords in Items File are:");
printf("\n");
i=1;
while((fread(&item,sizeof(Item),1,fh)>0))
{

	printf("\n\nRecord No:%d",i);
	printf("\nItem Id:%d",item.id);
	//printf("\nItem Id:%d",item.id);
	printf("\nName:%s",item.name);
	printf("\nPrice:%d",item.price);
	printf("\nQuantity:%d",item.quantity);
	i++;
}
fclose(fh);
}

void Find()
{

FILE *fh;

Item item;
int id1,found=0;

printf("\nEnter Id of item to Search Record=");
scanf("%d",&id1);
printf("item%d",id1);

/*open binary file in read mode*/
fh=fopen(BFILE,"rb");
if(fh==NULL)
{
printf("File could not open");
exit(0);
}

while((fread(&item,sizeof(Item),1,fh)>0))
{
	if(item.id == id1)
	{
	found=1;
	printf("\nInfo of Item With Id %d is as follows:",id1);

	printf("\nItem Id:%d",item.id);
	printf("\nName:%s",item.name);
	printf("\nPrice:%d",item.price);
	printf("\nQuantity:%d",item.quantity);

	break;
}
}
if(found==0)
   printf("\n Record Not found in this file!");
fclose(fh);
}

void Edit()
{
FILE *fh;
//int price,quantity;
//char name[20];
Item item;
int id1,i,flag=0;
char ch;
printf("\n Enter Id of item to Edit Record=");
scanf("%d",&id1);

/*open binary file in read mode*/
fh=fopen(BFILE,"rb+");
if(fh==NULL)
{
printf("File could not open");
exit(0);
}

while (fread(&item, sizeof(Item), 1, fh) > 0)
    {
        if (item.id == id1)
        {
            flag = 1;
            break;
        }
    }

if(flag)
   {
            long size = sizeof(Item);
            printf("\n1.Edit Name\n2.Edit Price\n3.Edit Quantity\n4.Edit All\nEnter Your Choice: ");
            fflush(stdin);
            scanf("%d",&i);
            printf("\n Order Id : %d", id1);
            //item.id = id1;
            switch(i)
            {
            case 1:
                printf("\n Enter Name of Item : ");
                fflush(stdin);
                gets(item.name);
                //strcpy(item.name,name);
                break;
            case 2:
                printf("\n Enter Price of Item : ");
                scanf("%d",&item.price);
                //item.price=price;
                break;
            case 3:
                printf("\n Enter Quantity of Item : ");
                scanf("%d",&item.quantity);
                //item.quantity=quantity;
                break;
            case 4:
                printf("\n Enter Name of Item : ");
                fflush(stdin);
                gets(item.name);
                printf("\n Enter Price of Item : ");
                scanf("%d", &item.price);
                printf("\n Enter Quantity of Item : ");
                scanf("%d", &item.quantity);
                break;
            }
           fseek(fh,-size,SEEK_CUR);
           fwrite(&item,sizeof(Item),1,fh);
           flag=1;
    }
   if(flag==0)
    {
        printf("\nOrder ID is not present....Please Try Again");
    }
    else
    {
        printf("\nItem Details Successfully Modified.Please check List");
    }
    fclose(fh);
}


void Delete()
{
    FILE *fp;
	FILE *fp_tmp;
	int found=0,id1;
	Item item;
    printf("Enter Item id to delete:");
    scanf("%d",&id1);

	fp=fopen(BFILE, "rb");
	if (!fp) {
		printf("Unable to open file");
		exit(1);
	}
	fp_tmp=fopen("temp.bin", "wb");
	if (!fp_tmp) {
		printf("Unable to open temp file.");
		exit(1);
	}
	
	while (fread(&item,sizeof(Item),1,fp) != 0) {
		if (item.id==id1) {
			printf("A record with requested name found and deleted.\n\n");
			found=1;
		} else {
			fwrite(&item, sizeof(Item), 1, fp_tmp);
		}
	}
	if (! found) {
		printf("No record(s) found with the Id: %d\n\n", id1);
	}

	fclose(fp);
	fclose(fp_tmp);

	remove(BFILE);
	rename("temp.bin", BFILE);

}
int main() {

 int i;

 printf("Welcome to Inventory Management System \n");
 do
 {
 printf("\nEnter options between 1-5\n");
 printf("1.Add Item to File\n");
 printf("2.Display all Item in File\n");
 printf("3.Find Item from File\n");
 printf("4.Edit Item info in File\n");
 printf("5.Delete Item from File\n");

 scanf("%d",&i);
 switch(i)
 {
  case 1: Add();
          break;

  case 2: Display();
          break;

  case 3: Find();
          break;

  case 4: Edit();
          break;

  case 5: Delete();
          break;
 }

 printf("\n\nPress 1 to Continue \nPress 0 to end\n");
 scanf("%d",&i);

}while(i);

}
