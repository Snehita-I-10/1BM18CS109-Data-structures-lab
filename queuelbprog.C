#include<stdio.h>
#include<process.h>
#define size 5
void enqueue(int *,int *);
void dequeue(int *,int *,int *);
void display(int *,int *,int *);

int main()
{
int r=-1,f=0,q[size],ch,item;
while(1)
{
printf("Enter 1:enqueqe\n2:dequeqe\n3.dispqelay\n4.exit");
scanf("%d",&ch);
switch(ch)
{
case 1:enqueue(q,&r);
	break;
case 2:dequeue(q,&f,&r);
	break;
case 3:display(q,&f,&r);
	break;
case 4:exit(0);
	break;
default:printf("wrong choice");
	break;
}
}

return 0;
}


void enqueue(int q[],int *r)
{       int item;

	if(*r==size-1)
	{
	printf("Queue is full");
	}
	else
	{
	printf("enter the value\n");
	scanf("%d",&item);
	(*r)++;
	q[*r]=item;
	}

}
void dequeue(int q[],int *f,int *r)
{
if(*f>*r)
{
printf("queue is empty\n");
}
else
{
printf("The element deleted is %d",q[*f]);
(*f)++;
}
}
void display(int q[],int *f,int *r)
{
	int i;
	if(*f>*r)
	{
	printf("Empty");
	}
	else
	{
	for(i=*f;i<=*r;i++)
	{
	printf("%d",q[i]);
	}
	}
}

