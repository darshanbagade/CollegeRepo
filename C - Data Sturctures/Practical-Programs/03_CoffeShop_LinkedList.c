// Program based on linked list:
//   2. Maintain a record of coffee shop database implement following:
//   i. Display the total sale of a day
//  ii. Maximum and minimum bill of a day
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int price;
    int quantity;
    char coffeeType[20];
    struct Node *next;
};
struct Node *head=NULL, *newnode, *temp;

int count=0;
struct Node* createNode(char coffeeType[10], int price, int quantity){
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->price = price;
    newnode->quantity = quantity;
    strcpy(newnode->coffeeType, coffeeType);
    count++;
    return newnode;
}

void insertAtEnd(char coffeeType[10], int price, int quantity){
    newnode = createNode(coffeeType, price, quantity);

    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        temp=head;
        while(temp->next != NULL){
            temp = temp->next ;
        }
        temp->next = newnode ;
        temp= newnode;
    }
    printf("Item Added\n");
}

void maxBill(){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    struct Node *max, *temp2;
    temp =temp2= max = head;
    while(temp != NULL){
        while(temp2 != NULL){
            if( (max->price) < (temp2->price) ){
                max = temp2;
            }
            temp2 = temp2->next;
        }
        temp= temp->next;
    }
    printf("\nMax Bill: Rs %d , Coffee Type : %s ,Quantity = %d \n",max->price, max->coffeeType, max->quantity);
}

void minBill(){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    struct Node *min, *temp2;
    temp =temp2= min = head;
    while(temp != NULL){
        while(temp2 != NULL){
            if( (min->price) > (temp2->price) ){
                min = temp2;
            }
            temp2 = temp2->next;
        }
        temp= temp->next;
    }
    printf("\nMin Bill: Rs %d , Coffee Type : %s ,Quantity = %d \n",min->price, min->coffeeType, min->quantity);
}

void displayList(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    else{
        temp = head;
        int srNo=1;
        while(temp != NULL){
            printf("%d. Coffee Type: %s , Price : %d, Quantity: %d \n",srNo, temp->coffeeType, temp->price, temp->quantity);
            srNo++ ;
            temp = temp->next;
        }
    }
}

int main(){
    while(1){
        int choice;
        printf("\n______________________________________\n");
        printf("\nSelect the option : ");
        printf("\n1.Add Coffee\n2.Display List\n3.Maximum Bill\n4.Minimum Bill\n5.Exit :");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            char coffeeType[10];
            int price;
            int quantity;
            printf("Enter coffee type:");
            scanf("%19s",coffeeType);

            printf("Quantity: ");
            scanf("%d",&quantity);
            printf("Total Price: ");
            scanf("%d",&price);
            insertAtEnd(coffeeType, price, quantity);
            break;
        case 2:
            printf("Item List:\n");
            displayList();
            break;
        case 3:
            maxBill();
            break;
        case 4:
            minBill();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid Choice !! Try Again");
        }

    }
    return 0;
}













