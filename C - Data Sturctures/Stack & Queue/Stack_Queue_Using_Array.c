#include<stdio.h>
//------------------------for stack------------------------------------
int top=-1;
int data;

//case 1: Push
void push(int arr[], int stack_arr[], int cap,int element){
    if(top==cap-1)
    {
        printf("--Stack Overflow--\n");
    }
    for(int i=0; i<element ;i++){
        if(top==cap-1)
        {
            printf("--Stack Overflow--\n");
        }
        top=top+1;
        stack_arr[top]=arr[top];
    }
}
//case 2: pop element
int pop(int stack_arr[]){
    int value=stack_arr[top];
    if(top==-1){
        printf("--Stack Underflow--\n");
    }
    top--;
    return value;
}
//case 3: peek element
int peek(int stack_arr[]){
    if(top==-1){
        printf("--Stack is empty--\n");
        return;
    }
    return stack_arr[top];
}
//case 4: display stack
void display_stack(int stack_arr[]){
    if(top==-1){
        printf("--Stack is Empty--\n");
        return;
    }
    for(int i=top ; i>=0 ;i--){
        printf("%d\n",stack_arr[i]);
    }
}
//case 5:display array
void display_arr(int arr[],int cap){
    for(int i=0;i<cap ;i++){
        printf("%d\n",arr[i]);
    }
}
void stack_operation(int arr[],int cap)
{
    int stack_arr[cap];
    int choice;
    int element;
    while(1){

        printf("---------------------\n");
        printf("Choose the operation:\n");
        printf("1.Push elements\n");
        printf("2.Pop element\n");
        printf("3.Top element\n");
        printf("4.Display Stack\n");
        printf("5.Display Array\n");
        printf("6.Quit from stack \t: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nHow many elements you want to push:");
            scanf("%d",&element);
            push(arr,stack_arr,cap,element);
            printf("Elements are pushed \n");
            break;
        case 2:
            data=pop(stack_arr);
            printf("-----------------\n");
            printf("Deleted element: %d\n",data);
            break;

        case  3:
            data=peek(stack_arr);
            printf("-----------------\n");
            printf("Top element: %d \n",data);
            break;
        case 4:
            printf("Stack Display:\n");
            display_stack(stack_arr);
            break;
        case 5:
            printf("Array Display:\n");
            display_arr(arr,cap);
            break;
        case 6:
            return;
        default:
            printf("Invalid Input");

        }
    }
}



//-----------------------------------------QUEUE OPERATIONS---------------------------------------------
int front=-1;
int rear=-1;
//case 1:enqueue
void enqueue(int arr[], int queue_arr[], int cap){
    if(rear==cap-1){
        printf("--Queue  Overflow--\n") ;
    }
    else if(front==-1 && rear==-1)//ENTER CONDITION FRONT>REAR
    {
            front=0;
            rear=0;
            queue_arr[rear]=arr[rear];
    }
    else{
        rear++;
        queue_arr[rear]=arr[rear];
    }
}
//case 2: dequeue
int dequeue(int queue_arr[])
{
    int value;
    if(front==-1 && rear==-1){
        printf("--Queue underflow--\n");
    }
    else if(front==rear){
        value=queue_arr[front];            
        front=-1;
        rear=-1;
    }
    else{
            value=queue_arr[front];
            front++;
    }
    return value;
}
//case 3:
int peek_queue(int queue_arr[]){
    if(front==-1){
        printf("--Stack is empty--\n");
        return;
    }
    return queue_arr[rear];
}
//case 4: display_queue
void display_queue(int queue_arr[]){
    for(int i=rear ; i>=front ;i--){
        printf("%d\n",queue_arr[i]);
    }
}
void queue_operation(int arr[],int cap)
{
    int queue_arr[cap];
    int choice;
    int element;
    while(1){

        printf("\n---------------------\n");
        printf("Choose the operation:\n");
        printf("1.Enqueue elements\n");
        printf("2.Dequeue element\n");
        printf("3.Top element\n");
        printf("4.Display Queue\n");
        printf("5.Display Array\n");
        printf("6.Quit from Queue \t: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            //printf("\nHow many elements you want to enque:");
            //scanf("%d",&element);
            enqueue(arr,queue_arr,cap);
            printf("Elements is enqueued \n");
            break;
        case 2:
            data=dequeue(queue_arr);
            printf("-----------------\n");
            printf("Deleted element: %d\n",data);
            break;

        case  3:
            data=peek_queue(queue_arr);
            printf("-----------------\n");
            printf("Top element: %d \n",data);
            break;
        case 4:
            printf("\n-----------------\n");
            printf("Queue Display:\n");
            display_queue(queue_arr);
            break;
        case 5:
            printf("Array Display:\n");
            display_arr(arr,cap);
            break;
        case 6:
            return;
        default:
            printf("Invalid Input");

        }
    }
}
//---------------------------------MAIN FUNCTION--------------------------------------------
int main()
{
    int cap;//capacity of arr
    int choose_structure;
    printf("Enter capacity of array : ");
    scanf("%d",&cap);
    int arr[cap];
    printf("Enter the %d elements :\n",cap);
    for(int i=0;i<cap;i++){
        scanf("%d",&arr[i]);
    }
    while(1){
        printf("\nChoose the data structure : \n");
        printf("1.Stack\n");
        printf("2.Queue\n");
        printf("3.Quit  \t:");
        scanf("%d",&choose_structure);
        switch(choose_structure)
        {
        case 1 :
            printf("Stack operations:\n");
            printf("-----------------\n");
            stack_operation(arr,cap);
            break;
        case 2:
            printf("Queue operations:\n");
            printf("-----------------\n");
            queue_operation(arr,cap);
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\nInvalid input");

        }
    }
}
