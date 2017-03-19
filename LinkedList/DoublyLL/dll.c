#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	struct node * prev;
	int data;
	struct node * next;
};

int InsertFirst(struct node ** head, int no)
{
	struct node * newnode=(struct node *)malloc(sizeof(struct node ));
	if(newnode==NULL)
	{
		return -1;
	}
	memset(newnode,0,sizeof(struct node));
	newnode->prev=NULL;
	newnode->data=no;
	newnode->next=NULL;

	if((*head)==NULL)
	{
		(*head)=newnode;
	}
	else
	{
		newnode-> next= (*head);
		(*head)=newnode;
		(*head)->prev=newnode;
	}
	return 1;
}


void Display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
			
}

int InsertLast(struct node **head, int no)
{
	struct node * newnode= (struct node *)malloc(sizeof(struct node ));
	struct node * temp=*head;
	if(newnode==NULL)
	{
		return -1;
	}
	memset(newnode,0,sizeof(struct node));
	newnode->prev=NULL;
	newnode->data=no;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode=temp->prev;
	}
	return 1;
}
int CountNode(struct node * head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
int InsertAtPosition(struct node ** head , int pos, int no)
{
	int i=0;
	if(*head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		InsertFirst(head,no);
	}
	else if(pos==(CountNode(*head))+1)
	{
		InsertLast(head,no);
	}
	else if(pos > (CountNode(*head)))
	{
		return -1;
	}
	else
	{
		struct node * temp=*head;
		struct node * newnode=(struct node *)malloc(sizeof(struct node ));
		memset(newnode,0,sizeof(struct node));
		newnode->prev=NULL;
		newnode->data=no;
		newnode->next=NULL;

		for(i=1;i<(pos-1);i++)
		{
			temp=temp->next;	
		}
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
	return 1;
}
int SearchFirst(struct node * head,int no)
{
	int pos=0;
	while(head!=NULL)
	{
		pos++;
		if(head->data==no)
		{
			return pos;
			break;
		}
		head=head->next;
	}
	return -1;
}

int SearchLast(struct node * head)
{
}
int SearchAllOccurance(struct node * head)
{
	int count=0;
	while(head!=NULL)
	{

	}
}
int DeleteFirst(struct node ** head)
{

}
int DeleteLast(struct node ** head)
{

}
int DeleteAtPosition(struct node ** head, int pos)
{

}
int DeleteAllNode(struct node ** head)
{

}

int ReverseList(struct node * head)
{

}





int main()
{
struct node * first=NULL;
InsertFirst(&first,10);
InsertFirst(&first,20);
InsertFirst(&first,30);
InsertFirst(&first,40);
InsertLast(&first,25);
Display(first);
printf("\n");
InsertAtPosition(&first,4,35);
Display(first);
printf("\nSearch First %d \n",SearchFirst(first,35));

return 0;	
}
