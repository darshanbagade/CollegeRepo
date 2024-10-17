#include<stdio.h>
#define MAX 7
char stack_arr[MAX];
int top=-1;// -1 represents stack is empty

void push(char data){
    if(top==MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
char pop(){
    char value=stack_arr[top];
    if(top==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    top= top-1;
    return value;
}
char peek(){
    return stack_arr[top];
}
void print(){
    if(top==-1){
        printf("Stack is empty\n");
        exit(1);
    }
    printf("\n");
    for(int i=top ; i>=0 ; i--){
        printf("%c\n",stack_arr[i]);
    }
}

int main(){
    int choice;
    char data;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Top element\n");
        printf("4.Display all the elements in the stack\n");
        printf("5.Quit\n");
        printf("Enter the correct choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf(" %c",&data);
            push(data);
            printf("---------------------------------\n");
            break;
        case 2:
            data=pop();
            printf("Deleted element : %c\n",data);
            printf("---------------------------------\n");
            break;
        case 3:
            data= peek();
            printf("Topmost element in the stack : %c\n",data);
            printf("---------------------------------\n");
            break;
        case 4:
            print();
            printf("---------------------------------\n");
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice! Please try again.\n");

        }
    }

}
