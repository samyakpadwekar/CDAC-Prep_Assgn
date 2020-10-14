/*Implement doubly linked list of bank accounts. 
Each account has information including id, type, balance and account holder. 
The account holder details include name, address & contact details. 
Write a menu-driven program to implement add first, add last, display all (forward), display all (backword), 
find by account id, find by account holder name, delete all functionalities.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct holder
{
 char name[20];
 char add[20];
 char num[20];
};

struct Account
{
 int id;
 char type[10];
 int bal;
 struct holder hol;
};

struct Node
{
 struct Account acc;
 struct Node* next;
 struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode() {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 printf("Enter Account Id: ");
 scanf("%d",&newNode->acc.id);
 fflush(stdin);
 printf("Enter Account Type(Savings/Current): ");
 gets(newNode->acc.type);
 printf("Enter Account Balance: ");
 scanf("%d",&newNode->acc.bal);
 fflush(stdin);
 printf("Enter Account Holder Name: ");
 gets(newNode->acc.hol.name);
 fflush(stdin);
 printf("Enter Account Holder Address: ");
 gets(newNode->acc.hol.add);
 fflush(stdin);
 printf("Enter Account Holder Phone Number: ");
 gets(newNode->acc.hol.num);
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}

void Addf()
{
 struct Node* newNode = GetNewNode();
 if(head == NULL) {
    head = newNode;
    return;
 }
 head->prev = newNode;
 newNode->next = head;
 head = newNode;
}

void Addb()
{
 struct Node* temp = head;
 struct Node* newNode = GetNewNode();
 if(head == NULL) {
    head = newNode;
    return;
 }
 while(temp->next != NULL) temp = temp->next; // Go To last Node
 temp->next = newNode;
 newNode->prev = temp;
}

void Dispf()
{
 struct Node* temp = head;
 printf("Forward: ");
 while(temp != NULL) {
    printf("Account Id:%d \n",temp->acc.id);
    printf("Account Type:%s \n",temp->acc.type);
    printf("Account Balance:%d \n",temp->acc.bal);
    printf("Account Holder Name:%s \n",temp->acc.hol.name);
    printf("Account Holder Address:%s \n",temp->acc.hol.add);
    printf("Account Holder Phone Number:%s \n",temp->acc.hol.num);
    printf("\n");
    temp = temp->next;
 }
 printf("\n");
}

void Dispb() {
 struct Node* temp = head;
 if(temp == NULL) return;

 while(temp->next != NULL) {
    temp = temp->next;
 }
 printf("Reverse: ");
 while(temp != NULL) {
    printf("Account Id:%d \n",temp->acc.id);
    printf("Account Type:%s \n",temp->acc.type);
    printf("Account Balance:%d \n",temp->acc.bal);
    printf("Account Holder Name:%s \n",temp->acc.hol.name);
    printf("Account Holder Address:%s \n",temp->acc.hol.add);
    printf("Account Holder Phone Number:%s \n",temp->acc.hol.num);
    printf("\n");
    temp = temp->prev;
 }
 printf("\n");
}

void FindById()
{
 int i = 1,data;
 printf("Enter Your Bank Acc id:");
 scanf("%d",&data);
 bool flag = false;
    //Node current will point to head
 struct Node *current = head;

    //Checks whether the list is empty
 if(head == NULL) {
  printf("List is empty\n");
  return;
 }
 while(current != NULL) {
        //Compare value to be searched with each node in the list
  if(current->acc.id == data)
  {
    flag = true;
    printf("Account Id:%d \n",current->acc.id);
    printf("Account Type(S for Savings,C for Current):%s \n",current->acc.type);
    printf("Account Balance:%d \n",current->acc.bal);
    printf("Account Holder Name:%s \n",current->acc.hol.name);
    printf("Account Holder Address:%s \n",current->acc.hol.add);
    printf("Account Holder Phone Number:%s \n",current->acc.hol.num);
    printf("\n");
    break;
  }
  current = current->next;
  i++;
  }

 if(flag)
    printf("Id is present in the list at the position : %d\n", i);
 else
    printf("Id is not present in the list\n");
}

void FindByName()
{
 int i = 1;
 char xname[20];
 printf("Enter Your Bank Acc Holder Name:");
 fflush(stdin);
 gets(xname);
 bool flag = false;
    //Node current will point to head
 struct Node *current = head;

    //Checks whether the list is empty
 if(head == NULL) {
  printf("List is empty\n");
  return;
 }
 while(current != NULL) {
        //Compare value to be searched with each node in the list
  if(!strcmp(current->acc.hol.name,xname))
  {
    flag = true;
    printf("Account Id:%d \n",current->acc.id);
    printf("Account Type(S for Savings,C for Current):%s \n",current->acc.type);
    printf("Account Balance:%d \n",current->acc.bal);
    printf("Account Holder Name:%s \n",current->acc.hol.name);
    printf("Account Holder Address:%s \n",current->acc.hol.add);
    printf("Account Holder Phone Number:%s \n",current->acc.hol.num);
    printf("\n");
    break;
  }
  current = current->next;
  i++;
  }

 if(flag)
    printf("Id is present in the list at the position : %d\n", i);
 else
    printf("Id is not present in the list\n");
}

void DeleteAll()
{
    struct Node *temp = head;
	if(temp==NULL)
	{
		printf("\n###LIST IS EMPTY###\n");
		return ;
	}
	struct Node *prevTemp;
	while(temp!=NULL)
	{
		prevTemp = temp;
		temp=temp->next;
		free(prevTemp);
	}
	head = NULL;
	printf("\nSuccessfully Deleted All element\n");
}

int main()
{
 head = NULL;
 int i;
 int j;

 printf("_____Bank Account Mangement_____\n");
 //scanf("%d",&i);
 printf("\n");
 do
 {
 printf("Enter options between 1-7\n");
 printf("1.Add Account details from front\n");
 printf("2.Add Account details from back\n");
 printf("3.Display Account record from front\n");
 printf("4.Display Account record from back\n");
 printf("5.Find by Account id\n");
 printf("6.Find by Account Holder name\n");
 printf("7.Delete all Accounts\n");

 printf("\nEnter Choice: ");
 scanf("%d",&i);
 switch(i)
 {
  case 1: Addf();
          break;

  case 2: Addb();
          break;

  case 3: Dispf();
          break;

  case 4: Dispb();
          break;

  case 5: FindById();
          break;

  case 6: FindByName();
          break;


  case 7: DeleteAll();
          break;
 }

 printf("\nPress 1 to Continue \nPress 0 to end\n");
 scanf("%d",&i);

}while(i);
 return(0);
}
