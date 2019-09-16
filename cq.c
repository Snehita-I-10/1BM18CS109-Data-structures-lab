#include<stdio.h>
#include<stdlib.h>
#define size 5
void enqueue(int q[],int *r,int *count)
{
int item;
printf("enter item to be inserted");
scanf("%d",&item);
if(*count>=size)
{printf("queue is full");
}

((*r)++)%size;
q[*r]=item;
*count=*count+1;


}
void dequeue(int q[],int *f,int *count)
{
	if(*count==0)
	printf("queue is empty");
	
	

	printf("Element deleted is %d",q[*f]);
	((*f)++)%size;
	*count=*count-1;

	
}
void display(int q[],int *f,int *count,int *r)
{
	int i;
	if(*count==0)
	printf("circular queue is empty");
	printf("\nElements in Circular Queue are: "); 
    if (*r >= *f) 
    { 
        for (int i = *f; i <= *r; i++) 
            printf("%d ",q[i]); 
    } 
    else
    { 
        for (int i = *f; i < size; i++) 
            printf("%d ", q[i]); 
  
        for (int i = 0; i <= *r; i++) 
            printf("%d ", q[i]); 
    } 
}

int main()
{
int q[size],r=-1,f=0,count=0,ch;
while(1)
{
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:enqueue(q,&r,&count);
		break;
	case 2:dequeue(q,&f,&count);
		break;
	case 3:display(q,&f,&count,&r);
		break;
	case 4:exit(1);
		break;
	default:printf("Invalid choice");
		break;
	}

}
return 0;
}


