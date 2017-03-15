#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
	int data;
	struct node * next;
};

int InsertFirst(struct node ** head, int no)
{
	struct node * newnode=(struct node *) malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		return 0;
	}
	memset(newnode,0,sizeof(struct node));
	
	newnode->data=no;
	newnode->next=NULL;
	
	if((*head)==NULL)
	{
		(*head)=newnode;	
	}
	else
	{
		newnode->next=(*head);
		(*head)=newnode;
	}
	return 0;
}

int InsertLast(struct node ** head, int no)
{
	struct node * temp=(*head);
	struct node * newnode=(struct node *) malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		return 0;
	}
	memset(newnode,0,sizeof(struct node));
	
	newnode->data=no;
	newnode->next=NULL;
	
	if((*head)==NULL)
	{
		(*head)=newnode;	
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return 0;
}

int CountNode(struct node * head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	//printf("\nCount of nodes %d\n ",count);
	return count;
}

int InsertAtPosition(struct node ** head, int no, int pos)
{
	int i=0;	
	struct node * temp=(*head);
	if(pos == 1)
	{
		InsertFirst(head,no);
	}
	else if(pos == (CountNode(*head)+1))
	{
		InsertLast(head,no);
	}
	else if(pos > (CountNode(*head)+1))
	{
		return 0;
	}
	else
	{
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
	memset(newnode,0,sizeof(struct node));
	newnode->data=no;	
	newnode->next=NULL;
		if(newnode==NULL)
		{
			return -1;
		}
	
		for(i=1;i<(pos-1);i++)
		{	
			temp=temp->next;
		}	
		newnode->next=temp->next;
		temp->next=newnode;
	}	
	
		return 0;
}
int SearchFirstOccurance(struct node * head,int no)
{
	int pos=-1;
	int count=0;
	while(head!=NULL)
	{
		++count;
		if(head->data==no)
		{
			pos=count;
			break;		
		}		
		head=head->next;
	}
	return pos;

}
int SearchLastOccarance(struct node * head)
{

}

int SearchAllOccurance(struct node * head, int no)
{
	//struct node * temp= head;
	int count=0;
	while(head!=NULL)
	{
		if(head->data==no)
		{
			count++;
			
		}	
		head=head->next;	
	}		
	return count;
}

int DeleteFirst(struct node ** head)
{
	struct node * temp=(*head);
	if(*head==NULL)
	{
		return -1;
	}
	else
	{
		(*head)=temp->next;
		free(temp);
	}
	return 1;
}
int DeleteLast(struct node ** head)
{
	struct node * temp1=(*head);
	struct node * temp2=(*head);
	if(*head==NULL)
	{
		return -1;
	}
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}	
	free(temp1);	
	temp2->next=NULL;	
	return 1;
}
int DeleteAtPosition(struct node ** head, int pos)
{
	if(*head==NULL)
	{
		return -1;
	}
	if(pos==1)
	{
		DeleteFirst(head);
	}
	else if(pos==(CountNode(*head)))
	{	
		DeleteLast(head);	
	}
	else if(pos==(CountNode(*head)+1))
	{	
		return -1;
	}
	else
	{
		struct node * temp1=(*head);
		struct node * temp2=(*head);

	 	for(int i=0;i<(pos-1);i++)
		{	
			//pos--;	
			temp2=temp1;
			temp1=temp1->next;		
		}
		temp2->next=temp1->next;
		temp1->next=NULL;
		free(temp1);
	}
	return 1;
}


int DeleteAllNodes(struct node ** head)
{
	
}

int ReverseList(struct node * head)
{

}

void Display(struct node * head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}



int main()
{
	struct node * first=NULL;
	InsertFirst(&first,10);	
	InsertFirst(&first,20);	
	InsertFirst(&first,30);	
	InsertFirst(&first,40);	
	InsertFirst(&first,30);
	InsertFirst(&first,30);	
	InsertFirst(&first,60);	
	InsertFirst(&first,70);	
	InsertLast(&first,80);
	InsertLast(&first,90);
	InsertLast(&first,15);
	printf("\n");
	Display(first);
	printf("\nTotal Count %d\n",CountNode(first));
	printf("InsertAt Position ");
	InsertAtPosition(&first,44,4);
	printf("\n");
	Display(first);
	printf("\nNode Searched at position %d\n ",SearchFirstOccurance(first,30));
	printf("\nSearch All Occarance %d \n",SearchAllOccurance(first,30));
	DeleteFirst(&first);	
	Display(first);
	printf("\n");
	DeleteLast(&first);	
	Display(first);
	printf("\nDeleteAtPosition \n");
	DeleteAtPosition(&first,4);
	Display(first);
return 0;
}
