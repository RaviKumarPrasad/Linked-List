

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertIn1st();
void insertInLast();
void display();
void isEmpty();
void deleteFrom1st();
void deleteFromLast();
void deleteRandom();
void insertRandom();

typedef struct Node
{
	int data;
	char name[10];
	struct Node * next;
}Node;

Node * head = NULL;

int main()
{
	while(1)
	{
		printf("\n==============================\n");
		printf("1. Create Node in first\n2. Create Node In last\n3. Display Nodes\n4. IsEmpty\n5. Delete from 1st\n6. Delete fron last\n7. Delete random\n8. insert random\n9. Exit\n");
		int ip;
		scanf("%d",&ip);
		switch(ip)
		{
			case 1: insertIn1st(); break;
			case 2: insertInLast(); break;
			case 3: display(); break;
			case 4: isEmpty(); break;
			case 5: deleteFrom1st(); break;
			case 6: deleteFromLast(); break;
			case 7: deleteRandom(); break;
			case 8: insertRandom(); break;
			case 9: exit(0);
			default: printf("\n Wrong input !!\n");
		}
	}
}

void insertIn1st()
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	int ip;
	char name1[10];
	printf("\nEnter value :>");
	scanf("%d%s",&ip,&name1);
	newNode->data=ip;
	strcpy(newNode->name,name1);
	newNode->next=head;
	head=newNode;
}

void display()
{
	if(head==NULL)	printf("List is Empty!!");
	else
	{
		Node * temp=head;
		while(temp!=NULL)
		{
			printf("\ndata -> %d name -> %s",temp->data,temp->name);
			temp=temp->next;
		}
	}
}

void insertInLast()
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	char name1[10];
	int ip;
	printf("\nEnter value :>");
	scanf("%d%s",&ip,&name1);
	newNode->data=ip;
	strcpy(newNode->name,name1);
	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;
	}
	else
	{
		Node * temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=NULL;
	}
		
}

void isEmpty()
{
	if(head==NULL)  printf("List is Empty!!");
	else 			printf("List is not Empty!!");
}

void deleteFrom1st()
{
	if(head==NULL)  printf("List is Empty!!");
	else
	{
		Node * temp=head;
		head=temp->next;
		printf(" Node with data %d has been deleted",temp->data);
		free(temp);
	}
}

void deleteFromLast()
{
	if(head==NULL)  printf("List is Empty!!");
	else
	{
		Node * temp, *ptr;
		temp=head;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf(" Node with data %d has been deleted",temp->data);
		free(temp);

	}
}

void deleteRandom()
{
	int ip;
	printf("Enter data id ");
	scanf("%d",&ip);
	Node * temp, *ptr;
	temp=head;
	if(head==NULL)			isEmpty();
	else
	{
		int check=0;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
			if(temp->data==ip)
			{
				ptr->next=temp->next;
				printf(" Node with data %d has been deleted",temp->data);
				free(temp);
				check=0;
				break;
			}
			else 		check=1;
		}
		if(check)       printf("Invalid ID!!");
	}
}

void insertRandom()
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	char name1[10];
	int ip;
	printf("\nEnter value :>");
	scanf("%d%s",&ip,&name1);
	newNode->data=ip;
	strcpy(newNode->name,name1);

	int loc;
	printf("Enter location :> ");
	scanf("%d",&loc);

	Node * temp=head;
	if(head==NULL)			isEmpty();
	else
	{
		for(int i=1;i<loc;i++)			temp=temp->next;
		newNode->next=temp->next;
		temp->next=newNode;
	}
}
