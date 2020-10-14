/*Implement a circular queue of students. 
Each student information includes roll, name, std, subject names and corresponding subject marks. 
Assume that each student holds subject names & marks of 6 subjects. 
Write a menu-driven program to implement push and pop functionality*/
#include<stdio.h>

typedef enum{EXIT,ENQUEUE,DEQUEUE,DISPLAY}operation;

typedef struct
{
	int marks;
}SUBJECT;

typedef struct
{
	int flag;
	int roll_no;
	char name[20];
	char std;
	SUBJECT physics;
	SUBJECT chemistry;
	SUBJECT mathematics;
	SUBJECT history;
	SUBJECT geography;
	SUBJECT marathi;
}STUDENT;
/*
int options();
int isfull();
int isempty();
void enque(STUDENT *stud);
void takeStudentData(STUDENT *stud);
void deque(STUDENT* stud);
void display_list(STUDENT* stud);
*/
#define MAX 5
int rear=-1,front=-1;

int options()
{
	int op;
	printf("\nEnter below option to perform operation on queue:\n");
	printf("0] EXIT\n1] ENQUEUE\n2] DEQUEUE\n3] DISPLAY\n");
	printf("ENTER OPTION: \n");
	scanf("%d",&op);
	return op;
}

int isfull()
{
	return (rear==MAX-1 && front==0)||(rear+1==front)?1:0 ;
}

int isempty()
{
	return (rear==-1 && front ==-1)?1:0 ;
}

void enque(STUDENT *stud)
{
	if(front==-1)
	{
		front=0;
	}

	if(rear== MAX-1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}

}

void takeStudentData(STUDENT *stud)
{
	stud->flag = 1;

	printf("\nEnter Roll No of Student: ");
	scanf("%d",&stud->roll_no);
	printf("\nEnter Name of Student :");
	scanf("%s",stud->name);
	getchar();
	//getchar();
	printf("\nEnter Standard/Class of Student :");
	scanf("%c",&stud->std);
	printf("\nEnter marks of physics :");
	scanf("%d",&stud->physics.marks);
	printf("\nEnter marks of chemistry :");
	scanf("%d",&stud->chemistry.marks);
	printf("\nEnter marks of mathematics :");
	scanf("%d",&stud->mathematics.marks);
	printf("\nEnter marks of history :");
	scanf("%d",&stud->history.marks);
	printf("\nEnter marks of geography :");
	scanf("%d",&stud->geography.marks);
	printf("\nEnter marks of marathi :");
	scanf("%d",&stud->marathi.marks);
}

void deque(STUDENT* stud)
{
	stud->flag=-1;
	if(front == rear)
	{
		rear =-1;
		front =-1;
	}
	else
	{
		if(front == MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}

}

void display_list(STUDENT* stud)
{
	for (int i = 0; i < 5; ++i)
		{
			if(stud[i].flag==1)
			{
				printf("\nInfo of Student %d ",i+1 );

				printf("\n Roll no :%d",stud[i].roll_no);
				printf("\n Name  :%s",stud[i].name);
				printf("\n Standard/Class   :%c",stud[i].std);
				printf("\n Physics Marks :%d",stud[i].physics.marks);
				printf("\n Chemistry Marks :%d",stud[i].chemistry.marks);
				printf("\n Mathematics Marks :%d",stud[i].mathematics.marks);
				printf("\n History Marks :%d",stud[i].history.marks);
				printf("\n Geography Marks :%d",stud[i].geography.marks);
				printf("\n Marathi Marks :%d\n",stud[i].marathi.marks);
			}
		}
}

int main()
{
	STUDENT stud[5];
	for (int i = 0; i < 5; ++i)
	{
		stud[i].flag = -1 ;

	}
	int op;
	while(op=options())
	{
	switch(op)
	{
		case ENQUEUE:
			if(isfull())
				{
					printf("queue is reached to its overflow condition\n");
				}
			else
				{
					enque(stud);
					takeStudentData(&stud[rear]);
				}
			break;
		case DEQUEUE:
			if(isempty())
			{
				printf("queue is under underflow condition\n");
			}
			else
			{
			deque(&stud[front]);
		    }
			break;
		case DISPLAY:
			display_list(stud);
			break;
		default:
			printf("Enter valid option\n");
	}
	}
}
