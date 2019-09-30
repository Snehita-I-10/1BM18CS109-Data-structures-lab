#include <stdio.h>
#include <stdlib.h>

struct node{
	int val,pos,iem;
	struct node *next;
	};
	
typedef struct node* node;

node get_node();
node ins_front(node first, int val);
node ins_back(node first, int val);
node delete_front(node first);
node delete_back(node first);
node insert_pos(node first, int pos,int item);
node delete_pos(node first, int pos);
void display(node first);

node first = NULL;

int main(){
	int i, x, val,item,pos;
	
	while(1){
		printf("1: Enter value from front\n");
		printf("2: Enter value from back\n");
		printf("3: Delete from front\n");
		printf("4: Delete from back\n");
		printf("5: Insert at given position\n");
		printf("6: Delete at given position\n");
		printf("7: Display\n");
		
		scanf("%d", &x);
			switch(x){
			case 1:
				printf("Enter value from front: ");
				scanf("%d", &val);
				first = ins_front(first, val);
				break;
				
			case 2:
				printf("Enter value from back: ");
				scanf("%d", &val);
				first = ins_back(first, val);
				break;
			case 3:
				first=delete_front(first);
				break;

			case 4:
				first=delete_back(first);
				break;
			case 5:printf("Enter the position of the node to be inserted");
				scanf("%d",&pos);
				printf("Enter  the item to be inserted");
				scanf("%d",&item);
				first=insert_pos(first,pos,item);
				break;
			case 6:printf("Enter the position of the node to be deleted");
				scanf("%d",&pos);
				first=delete_pos(first,pos);
				break;

			case 7:
				display(first);
				break;
			default:printf("Wrong choice");
			         break;
			}
		}
	}
		
node get_node(){
	node temp;
	temp = (node)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
	}
	
	

node ins_front(node first, int val){
	node temp;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		temp = get_node();
		temp->val = val;
		temp->next = first;
		first = temp;
		
		}
	return first;	
	}

node ins_back(node first, int val){
	node temp, curr;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		curr  = first;
		while(curr->next != NULL){
			curr = curr->next;
			}
				 
		temp = get_node();
		temp->val = val;
		curr->next = temp;
		}
	return first;
	}
node delete_front(node first)
{
	node temp;
	temp=first;
	if(first==NULL)
	printf("Not possible");
	temp=first->next;
	printf("The deleted element is %d",first->val);
	free(first);
	return temp;

}
node delete_back(node first)
{
	node last,seclast;
	last=first;
	seclast=NULL;
	if(first==NULL)
	printf("Not possible");
	while(last->next!=NULL)
	{
		seclast=last;
		last=last->next;
	}
	seclast->next=NULL;
	printf("The deleted element is %d",last->val);
	free(last);
	return first;
}
node insert_pos(node first,int pos,int item)
{
	node temp,cur,pre;
	int count=1;
	cur=first;
	pre=NULL;
	temp=get_node();
	temp->val=item;
	temp->next=NULL;
	if(first==NULL && pos==1)
	{	return temp;
	}
	if(first==NULL && pos!=1)
	{	printf("Not possible");
		
	}
	while(cur->next!=NULL && count!=pos)
	{
		pre=cur;
		cur=cur->next;
		count++;
	}
	if(count==pos)
	{
	pre->next=temp;
	temp->next=cur;
	}
	else
	{printf("Invalid position");
	}
	return first;



}
node delete_pos(node first,int pos)
{
	node cur,pre;
	cur=first;
	pre=NULL;
	int count=1;
	if(first==NULL)
	printf("Not possible");
	if(first->next==NULL && pos==1)
	{
	free(first);
	return NULL;
	}
	while(cur->next!=NULL && count!=pos)
	{
		pre=cur;
		cur=cur->next;
		count++;
	}
	if(count==pos)
	{
	pre->next=cur->next;
	printf("The deleted element is %d",cur->val);
	free(cur);
	}
	else
	{printf("Invalid pos");
	}
	return first;
}
void display(node first){
	node curr;
	curr = first;
	while(curr != NULL){
		printf("%d\n", curr->val);
		curr = curr->next;
		}
	}
		
