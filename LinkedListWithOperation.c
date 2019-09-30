

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
void reverseList();
void swapTwoNodes();
void sort();

typedef struct Node
{
	int data;
	char name[10];
	Node * next;
}Node;

Node * head = NULL;

int main()
{
	while(1)
	{
		printf("\n==============================\n");
		printf("1. Create Node in first\n2. Create Node In last\n3. Display Nodes\n4. IsEmpty\n5. Delete from 1st\n6. Delete fron last\n7. Delete random\n8. insert random\n9. ReverseList \n10. Exit\n11. swap nodes\n12. sort\n");
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
			case 9: reverseList(); break;
			case 10: exit(0);
			case 11: swapTwoNodes(); break;
			case 12: sort();  break;
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

void reverseList()
{
	Node * prevNode,* curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
	}
	
}

void swapTwoNodes()
{
	Node * ptr1, *ptr2;
	ptr1=ptr2=head;
	int node1,node2;
	printf("Enter two adress of Node to swap(only data) ");
	scanf("%d%d",&node1,&node2);
	int count=0;
	while(ptr1!=NULL)
	{
		count++;
		if(count==node1)
		{
			break;
		}
		ptr1=ptr1->next;
	}
	count=0;
	while(ptr2->next!=NULL)
	{
		count++;
		if(count==node2)
		{
			break;
		}
		ptr2=ptr2->next;
	}
	int temp;
	temp=ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=temp;

}
void sort()
{
	for(Node * itr1=head;itr1->next!=NULL;itr1=itr1->next)
	{
		for(Node * itr2=itr1->next;itr2!=NULL;itr2=itr2->next)
		{
			if(itr1->data>itr2->data)
			{
				int temp=itr1->data;
				itr1->data=itr2->data;
				itr2->data=temp;
			}
		}
	}
}
