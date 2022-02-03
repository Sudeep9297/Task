#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* createnode(struct node*);
void display(struct node*);
void search(struct node*);

struct node
{
char name[30],city[20],country[20];
int sno,id;
struct node* ptr;
};

int main()
{
struct node* head;
int b,i,j=0;

head=NULL;

while(1)
{
 printf("\nEnter the value\n1.to enter the employee details\n2.to display the employee details\n3.to search employee sno\n");
 scanf("%d",&b);

	switch(b)
	{
		case (1): printf("\nEnter the number of employee details you would like to enter:\t");
          		  scanf("%d",&i);
   					for(j=0;j<i;j++)
   					{
   						head=createnode(head);
 				   	 }
 				   	 break;

		case (2): display(head);
         		  break;

		case (3): search(head);
        		  break;  
	}
}
}


void display(struct node* head)
{
	if(head==NULL)
	{
		printf("\nThe node is yet to be displayed\n");
	}

	else
	{
		while(head!=NULL)
		{	
			printf("\nemp_name    :%s\t",head->name);
			printf("\nemp_sno     :%d\t",head->sno);
			printf("\nemp_id      :%d\t",head->id);
			printf("\nemp_city    :%s\t",head->city);
			printf("\nemp_country :%s\t",head->country);
			printf("\n----------------------------------\n");
			head=head->ptr;
		}
	}
}

struct node* createnode(struct node* head)
{
 struct node* newnode;
 newnode=(struct node*)malloc(sizeof (struct node));

			printf("\nEnter the employee name :\t");
			scanf("%s",newnode->name);
			printf("Enter the sno of the employee :\t");
			scanf("%d",&newnode->sno);
			printf("Enter the id of the employee :\t");
			scanf("%d",&newnode->id);
			printf("Enter the city of the employee :\t");
			scanf("%s",newnode->city);
			printf("Enter the country of the employee :\t");
			scanf("%s",newnode->country);
		
			
			if(newnode == NULL)
			{
				printf("\n Enter the newnode \n");
				newnode->ptr=NULL;
			}
			else
			{
				newnode->ptr=head;
			}
			return newnode;
			}


void search(struct node* head)
{
int id;

printf("\nEnter the searched id\n");
scanf("%d",&id);


while(head!=NULL)
	{
		if(id==head->id)
	{
		printf("\nThe element is matched\n");
		printf("The name of the searched employee id is %s\n",head->name);
		printf("The serial no of the searched employee id is %d\n",head->sno);
		printf("The city of the searched employee id is %s\n",head->city);
		printf("The country of the searched employee id is %s\n",head->country);
		printf("-------------------------------------------------------------------------------------------------------\n");
		printf("The name of the searched employee id is %s\n",head->ptr->name);
		printf("The serial no of the searched employee id is %d\n",head->ptr->sno);
		printf("The city of the searched employee id is %s\n",head->ptr->city);
		printf("The country of the searched employee id is %s\n",head->ptr->country);
	}

	else 
	{
		printf("\nThe element is not matched\n");
	}
	head=head->ptr;
	}
}

