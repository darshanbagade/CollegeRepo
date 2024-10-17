#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* left;
    struct node* right;

};
int insert(struct node* root){
    struct node* newnode;
    newnode->left=NULL;
    newnode->right=NULL;
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if(root==NULL){
        root=newnode;
    }
}
int main(){
    struct node *root;
    root=NULL;
    int choice
    while(choice){
        int choose;
        printf("\nChoose the operation: \n1.Insert Element\n2.Exit \t:");
        scanf("%d",&choose);
        switch(choose){
        case 1:
            insert(root);
        case 2:
            exit(1);
        }
    }
}
