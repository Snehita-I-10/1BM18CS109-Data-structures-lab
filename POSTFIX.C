#include<stdio.h>
#include<conio.h>
int stack[20],top=-1;
int pop()
{
	return stack[top--];
}
void push(int p)
{
	stack[++top]=p;
}

int main()
{
	int x1,x2,x,a,b,y;
	char expr[20],*s;
	printf("Enter the Postfix expression:\n");
	scanf("%s",expr);
	s=expr;
	while(*s!='\0')
	{	if(isdigit(*s))
		{
			x=*s-48;
			push(x);
		}
		else
		{      a=pop();
			b=pop();
			switch(*s)
			{
				case '+':
					{
					y=a+b;
					break;
					}
				case '-':
					{
					y=a-b;
					break;
					}
				case '*':
					{
					y=a*b;
					break;
					}
				case '/':
					{
					y=a/b;
					break;
					}
			}
			push(y);
		}
		s++;
	}

	printf("The resultant of the postfix expression %s is:%d",expr,pop());
	getch();
	return 0;
}


