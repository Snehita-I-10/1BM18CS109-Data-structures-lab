#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push(int ele,int s[5],int *t);
int pop(int s[5],int *t);
void display(int s[5],int t);
int main()
{
int stack[5],top=-1,e,ele,ch;
do
{
printf("1.push\n2.pop\n3.display\n.4.exit\n");
printf("Enter choice");
scanf("%d",&ch);
	switch(ch)
	{	case 1:printf("Enter the element to be pushed\n");
			scanf("%d",&ele);
			push(ele,stack,&top);
			break;

	case 2:e=pop(stack,&top);
		if(e!=9999)
		{
		printf("The popped element is %d\n",e);
		}
		break;
	case 3:display(stack,top);
		break;
	case 4: exit(0);
		break;
	default:printf("wrong choice");
		break;
	}
}while(ch!=4);
getch();
return 0;
}
void push(int ele,int s[5],int *t)
{
	if(*t==4)
	{	printf("Stack overflow");
		return;
	}
	else
	{       *t=*t+1;
		s[*t]=ele;
	}
}
int pop(int s[5],int *t)
{
	int x;
	if(*t==-1)
	{	printf("Stack underflow");
		return 9999;
	}
	x=s[*t];
	*t=*t-1;
	return x;
}
void display(int s[5],int t)
{       int i;
	if(t==-1)
	{
	printf("Stack is Empty\n'");
	return;
	}
	for(i=t;i>=0;i--)
	{
	printf("%d\n",s[i]);
	}
}




