#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(int *head){
    struct node *temp;
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node *head,*newnode,*temp;
    head=NULL;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element to insert :");
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
    printf("Display of Linked list:\n")
    display(head);
}
