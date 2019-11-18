#include<stdio.h>
#include<stdlib.h>
struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
};
typedef struct Node* node;
node first=NULL;
node getnode();
node insert_end(int item,node first);
node del_val(int val,node first);
node insert_left(int item,int pos,node first);
void display(node first);


node getnode()
{
	node temp;
	temp=(node)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

node insert_end(int item,node first)
{
	
	node temp,cur=first;
	temp=getnode();
	temp->value=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(first==NULL)
		return temp;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=temp;
	temp->prev=cur;
	return first;
	
}
node del_val(int val,node first)
{
	node cur=first,pre=NULL,temp;
	while(cur->next!=NULL)
	{	
		if(cur->value==val)
		{
			(cur->prev)->next=cur->next;
			(cur->next)->prev=cur->prev;
			temp=cur->next;
			free(cur);
			cur=temp;
			
		}
		else
		cur=cur->next;
	}
	return first;
}
node insert_left(int item,int pos,node first)
{
	node temp,cur=first;
	int count=1;
	temp=getnode();
	temp->value=item;
	temp->prev=NULL;
	temp->next=NULL;
	if(first==NULL && pos==2)
		return temp;
	else if(first==NULL && pos!=2)
		printf("Not possible");
		else
		{
	while(cur->next!=NULL && count!=pos)
	{
		cur=cur->next;
		count++;
	}
	if(count==pos)
	{
		(cur->prev)->next=temp;
		temp->prev=cur->prev;
		temp->next=cur;
		cur->prev=temp;
	}
	else
		printf("Cannot insert");
		}
	return first;
	
}	
void display(node first)
{
node cur=first;
while(cur!=NULL)
{
	printf("%d ",cur->value);
	cur=cur->next;
}
}
void main()
{	int ch,item,val,pos;
	while(1)
	{
	printf("Enter 1:insert at end\n2:Delete the given val\n3:insert at left of a node\n4:display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter item to be inserted");
		scanf("%d",&item);
		first=insert_end(item,first);
		break;
		case 2:printf("enter value of the node to be delted");
		scanf("%d",&val);
		first=del_val(val,first);
		break;
		case 3:printf("enter item to be inserted and pos");
		scanf("%d\n%d",&item,&pos);
		first=insert_left(item,pos,first);
		break;
		case 4:display(first);
		break;
		}
	}
		
}



	
