#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50

int stack[MAX_SIZE] ={0};
char str[MAX_SIZE];
int top = -1;

void push(char data){
    if(top == MAX_SIZE -1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    char data = stack[top];
    top--;
    return data;
}


void reverseString(){
    int length = strlen(str);

    for(int i=0 ; i<length ;i++){
        push(str[i]);
    }

    for(int i=0 ; i<length ; i++){
        str[i] = pop();
    }
}

int main(){
    printf("Enter the String : ");
    scanf("%s",str);


    printf("\n----------------------\n");
    printf("Original string : %s\n",str);

    reverseString();

    printf("Reversed String: %s", str);
}

