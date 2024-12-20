#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL,*newnode, *temp, *parent;

struct node* createNode(int data){
    newnode = (struct node*)malloc( sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    return newnode;
}

void insert(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    newnode = createNode(data);
    if(root == NULL){
        root = newnode;
    }
    else{
        temp = parent = root ;
        while(temp!=NULL){
            parent=temp;
            if(data > temp->data){
                temp = temp->right;
            }
            else if(data < temp->data){
                temp = temp->left;
            }
            else{
                temp= temp->left;
            }
        }
        if(data > parent->data){
            parent->right = newnode;
        }
        else if(data < parent->data){
            parent->left = newnode;
        }
        else{
            parent->left = newnode;
        }
    }

}

void inorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    printf("%d, ",temp->data);
    inorder(temp->right);
}

void preorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    printf("%d ,",temp->data);
    preorder(temp->left);
    preorder(temp->right);

}
void postorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d, ",temp->data);
}

int main(){
     while(1){
        int option;
        printf("- - - Select the option - - -\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete\n");
        printf("6. Exit\t  :");

        scanf("%d", &option);
        switch(option){
        case 1:
            insert();
            break;
        case 2:
            if(root==NULL){
                printf("No elements present in a tree\n");
            }
            else{
                printf("Inorder Traversal :");
                inorder(root);
                printf("\n");
            }
            break;
        case 3:
            if(root==NULL){
                printf("No elements present in a tree\n");
            }
            else{
                printf("Preorder Traversal :");
                preorder(root);
            }
            printf("\n");
            break;
        case 4:
            if(root==NULL){
                printf("No elements present in a tree\n");
            }
            else{
                printf("Postorder Traversal :");
                postorder(root);
            }
            printf("\n");
        /*case 5:
            delete();
            break;*/
        case 6:
            exit(1);
        default:
            printf("Invalid Input ! PLease try again : \n");

        }
     }
}
