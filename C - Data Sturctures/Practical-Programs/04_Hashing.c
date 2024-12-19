#include<stdio.h>
#include<stdlib.h>
#define tableSize 10
struct node{
 int data;
 struct node *next;
};
struct node *head[tableSize]={NULL},*temp,*newnode;


void insert(){
    int key,index;
    printf("Enter the key: ");
    scanf("%d", &key);
    index = key % tableSize;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if(head[index] == NULL){
        head[index] = newnode;
    }
    else{
        temp = head[index];
        while( temp->next != NULL ){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("%d is inserted\n", key);
}
void search(){
    int key,index;
    printf("Enter the key you want to search:\n");
    scanf("%d", &key);
    index = key % tableSize;
    temp = head[index];
    while(temp != NULL){
        if(temp->data == key){
            printf("Key found at index %d",index);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found\n");
}
void display(){
    for(int i=0; i < tableSize ; i++){
        printf("\nEnteries at index %d : ",i);
        temp = head[i];
        if(temp == NULL){
            printf("No Hash Entry");
        }
        else{
            while(temp != NULL){
                printf("%d->", temp->data);
                temp= temp->next;
            }

        }
    }
}
int main(){
    int option;
    while(1){
            printf("\n________________________________________\n");
            printf("Select the option:\n");
            printf("1. Insert key\n");
            printf("2. Display hash table\n");
            printf("3. Search key \n");
            printf("4. Exit\t:");
            scanf("%d", &option);
        switch(option){
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Input !\n");

        }
    }
}
