#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL,*newnode,*temp;
int count=0;
struct Node* createNode(int data){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    count++;
    return newnode;
}
int insertAtBeginning(){
    int data;
    printf("Enter the data :");
    scanf("%d",&data);
    newnode = createNode(data);
    temp=head;
    head=newnode;
    newnode->next=temp;
    return data;
}
int insertAtEnd(){
    int data;
    printf("Enter the data :");
    scanf("%d",&data);
    newnode=createNode(data);
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return data;
}
void insertAtPosition(){
    int pos;
    int i=1;
    printf("Enter position : ");
    scanf("%d",&pos);
    int data;
    printf("Enter the data :");
    scanf("%d",&data);
    newnode=createNode(data);
    if(pos>count || pos<1){
        printf("\nInvalid Position \n.");
        return;
    }
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp=head;
        while(i<pos-1){

            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("Node inserted at position %d\n",pos);
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("\nList is Empty.\n");
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
        count--;
    }
}
void deleteAtEnd(){
    struct Node *nextnode;
    if(head==NULL){
        printf("\nList is Empty.\n");
        return;
    }
    if (head->next == NULL) { // Only one node
        free(head);
        head = NULL;
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        nextnode=temp->next;
        temp->next=NULL;
        free(nextnode);
    }
        count--;
}
void deleteAtPosition(){
    struct Node *nextnode;
    int i=1;
    int pos;
    if(pos>count || pos<1){
        printf("\nInvalid Position \n.");
    }
    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
    count--;
    printf("\nNode at %d position is deleted\n",pos);
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
    int ans=0;
    int choice=1;
    int option;
    while(choice){
        printf("\n--Choose Option--\n");
        printf("1.Insert a node at Beginning \n2.Insert a node at end\n3.Insert a node at any position\n4.Delete a node at Beginning \n5.Delete a node at end\n6.Delete a node at any position\n7.Display List\n8.Exit\t: ");
        scanf("%d",&option);
        switch(option){
    case 1:
        ans = insertAtBeginning();
        printf("%d inserted at beginning\n",ans);
        break;
    case 2:
        ans = insertAtEnd();
        printf("%d inserted at end\n",ans);
        break;
    case 3:
        insertAtPosition();
        break;
    case 4:
        deleteAtBeginning();
        printf("First node is deleted\n");
        break;
    case 5:
        deleteAtEnd();
        printf("Last node is deleted\n");
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
