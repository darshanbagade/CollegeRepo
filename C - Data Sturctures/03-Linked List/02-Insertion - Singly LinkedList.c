#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*newnode,*temp;
int count=0;

//-----------------Insert at begining--------------------------//
void insert_begin(){
    newnode=(struct node*)malloc(sizeof(struct node));
    count++;
    printf("Enter the element to insert at begining:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf("%d is inserted at begining.\n",newnode->data);
}

//-------------------Insert at end-------------------------------//
void insert_end(){
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    count++;
    printf("Enter the element to insert at end:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("%d is inserted at end.\n",newnode->data);

}
//-------------Insert at specific Position---------------------//
void insert_postion(){
    int i=1;
    int pos;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the element:");
    scanf("%d",&newnode->data);
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    else if(pos>count){
        printf("Invalid Position");
    }
    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("%d inserted at %d position.\n",newnode->data,pos);
}
//------------------Display Linked List----------------------//
void display(){
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        count++;        printf("Enter the element to insert :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue insertion of element(1/0):");
        scanf("%d",&choice);
    }
    printf("Display of Linked list:\n");
    display(head);
    while(1){
        int choose;
        printf("\n-------------------------");
        printf("\nEnter the Choice:\n");
        printf("1.Insert at begining\n2.Insert at end\n3.Insert at position\t:");
        scanf("%d",&choose);
        switch(choose){
    case 1:
        insert_begin();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        insert_postion();
        count++;
        break;
 /*   case 4:
        delete_begin();
        break;
    case 5:
        delete_end();
        break;
    case 6:
        delete_position();
        break;*/
    case 7:
        display();
        break;
    case 8:
        exit(1);
    default:
        printf("Invalid input");
        }
    }
}
