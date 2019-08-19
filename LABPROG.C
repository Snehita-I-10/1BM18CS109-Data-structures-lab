#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 3
void push(void);
void pop(void);
void display(void);
int top=-1,i,ch,item,stack[n];
void main()
{

while(1)
{       printf("Enter your choice\n");
	printf("1.push()\n2.pop()\n3.display()\n4.exit\n");

	scanf("%d",&ch);

	switch(ch)
	{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:display();
			break;
		case 4:exit(0);
		default:printf("Wrong Choice! Please enter proper choice(1/2/3/4)");
			break;
	}
}


}
void push()
{
	if(top>=n-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		printf("Enter the item to be inserted");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
}
void pop()
{
	if(top<0)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("Element removed is %d\n",stack[top]);
		top--;
	}
}
void display()
{
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}

