#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
int data;
struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
int i,key;
printf("\nEnter a value to insert into hash table\n");
scanf("%d",&key);
i=key%TABLE_SIZE;
struct node * newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=key;
newnode->next = NULL;
if(head[i] == NULL)
head[i] = newnode;
else
{
c=head[i];
while(c->next != NULL)
{
c=c->next;
}
c->next=newnode;
}
}
void search()
{
int key,index;
printf("\nEnter the element to be searched\n");
scanf("%d",&key);
index=key%TABLE_SIZE;
if(head[index] == NULL)
printf("\nSearch element not found\n");
else
{
for(c=head[index];c!=NULL;c=c->next)
{

if(c->data == key)
{
printf("Search element found\n");
break;
}
}
if(c==NULL)
printf("\nSearch element not found\n");
}
}
void display()
{
int i;
for(i=0;i<TABLE_SIZE;i++)
{
printf("\nEntries at index %d\n",i);
if(head[i] == NULL)
{
printf("No Hash Entry");
}
else
{
for(c=head[i];c!=NULL;c=c->next)
printf("%d->",c->data);
}
}
}
int main()
{
int opt,key,i;
while(1)
{
printf("\nPress 1. Insert\t 2. Display \t 3. Search \t 4.Exit \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
insert();
break;
case 2:
display();
break;
case 3:

search();
break;
case 4:exit(0);
}
}
}