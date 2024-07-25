#include<stdio.h>
int top=-1;

//case 1 : push
void push(int arr[], int stack_arr[] , int cap, int element ){
            if(top==cap-1){
            printf("Stack overflow\n");
            return;
            }
    for(int i=0 ; i<element ; i++){
            top=top+1;
            stack_arr[top]=arr[top];
    }

}

//case 2 : Pop
int pop(int stack_arr[]){
    int value=stack_arr[top];
    if(top==-1){
        printf("Stack Underflow\n");
    }
    top=top-1;
    return value;
}

//case 3 : return top element
int peek(int stack_arr[]){
    if(top==-1){
        printf("Stack is empty.\n");
        return;
    }
    return stack_arr[top];
}

//case 4: Display stack
void display(int stack_arr[]){
    if(top==-1){
        printf("Stack is empty");
        return;

    }

    for(int i=top ; i>=0 ; i--){
        printf("%d\n",stack_arr[i]);
    }

}
int main(){
    int cap;//capacity of array
    int data;
    printf("Enter the capacity of array : ");
    scanf("%d",&cap);
    int stack_arr[cap];
    int arr[cap];
    printf("\nEnter the elements :\n");
    for(int i=0 ; i< cap ; i++){
        scanf("%d",&arr[i]);
    }
    while(1){
        int choice=0;
        printf("\n\nEnter Correct Choice:\n");
        printf("1.Push the element\n");
        printf("2.Pop the element\n");
        printf("3.Top element of the Stack\n");
        printf("4.Display elements in the Stack\n");
        printf("5.Quit : \t");
        scanf("%d",&choice);
        printf("\n------------------\n");
        switch(choice){
        case 1:
            int element=0;
            printf("\nHow many element you want to push into the stack: ");
            scanf("%d",&element);
            push(arr,stack_arr,cap,element);
            printf("Elements are pushed\n");
            break;
        case 2:
            int k=pop(stack_arr);
            printf("Deleted element : %d \n\n",k);
            break;
        case 3:
            data=peek(stack_arr);
            printf("Top element : %d",data);
            break;
        case 4:
            printf("Display of Stack :\n");
            display(stack_arr);
            break;
        case 5:
            exit(1);
            break;
        }
    }

}
