#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL,*newnode,*temp,*nextnode;
int count=0;
struct Node* createNode(int data){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->prev=NULL;
    newnode->next=NULL;
    newnode->data=data;
    count++;
    return newnode;

}
void insertAtBeginning(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    newnode=createNode(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        head=newnode;
        head->next=temp;
        temp->prev=newnode;
    }
    printf("\nNode is inserted at Beginning.\n");
}
void insertAtEnd(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    newnode=createNode(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("\n%d is inserted at end.\n",data);
}
void insertAtPosition(){
    int data;
    int pos;
    int i=1;
    printf("Enter Position : ");
    scanf("%d",&pos);
    printf("Enter data: ");
    scanf("%d",&data);
    newnode=createNode(data);
    if(pos>=count+1 || pos<1){
        printf("\nInvalid position\n");
        return;
    }
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
    printf("\n%d is inserted at %d position.\n",data,pos);
}

void deleteAtBeginning(){
    if(head==NULL){
        printf("\nList is Empty.\n");
        return;
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
        count--;

    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
        count--;
    }
    printf("\nFirst node is deleted.\n");
}
void deleteAtEnd(){
    if(head==NULL){
        head=newnode;
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
        count--;

    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        nextnode=temp->next;
        temp->next=NULL;
        free(nextnode);
        count--;
    }
    printf("\nLast node is deleted.\n");
}
void deleteAtPosition(){
    int pos;
    int i=1;
    printf("Enter Position : ");
    scanf("%d",&pos);
    if(head==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        if (nextnode->next != NULL) {   // If it's not the last node
        nextnode->next->prev = temp; // Update the previous pointer of the next node
    }
        free(nextnode);
        count--;
    }
    printf("\nNode at %d position is deleted.\n",pos);
}
void displayList(){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(){
    int data;
    int choice=1;
    int option;
    while(choice){
        printf("\n--Choose Option--\n");
        printf("1.Insert a node at Beginning \n2.Insert a node at end\n3.Insert a node at any position\n4.Delete a node at Beginning \n5.Delete a node at end\n6.Delete a node at any position\n7.Display List\n8.Exit\t: ");
        scanf("%d",&option);
        switch(option){
    case 1:
        insertAtBeginning();
        break;
    case 2:
        insertAtEnd();

        break;
    case 3:
        insertAtPosition();
        break;
    case 4:
        deleteAtBeginning();
        break;
    case 5:
        deleteAtEnd();
        break;
    case 6:
        deleteAtPosition();
        break;
    case 7:
        printf("Display List :\n");
        displayList();
        break;
    case 8:
        exit(1);
    default:
        printf("Invalid input");

        }
        printf("\nDo you want to continue(1/0):");
        scanf("%d",&choice);
    }
}
