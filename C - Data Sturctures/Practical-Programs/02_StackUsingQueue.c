#include<stdio.h>
#include<stdlib.h>
#define cap 5
int s1[cap];
int s2[cap];
int top1=-1;
int top2=-1;
int count=0;
int value;
void enque(int data){
    push1(data);
    count++;
}
void dequeue(){
    int a;
    if(top1==-1){
        printf("\nQueue is Empty.");
        return;
    }
    else{
        for(int i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        //pop2();
        printf("\n%d is dequeued",pop2());
        count--;
        for(int i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }

}
void push1(int data){
    if(top1==cap-1){
        printf("\nQueue is Overflow.");
        return 0;
    }
    else{
        top1++;
        s1[top1]=data;
    }
}
void push2(int data){
    if(top2==cap-1){
        printf("\nQueue is Overflow.");
        return;
    }
    top2++;
    s2[top2]=data;
}
int pop1(){
    value=s1[top1];
    top1--;
    return value;
}
int pop2(){
    value=s2[top2];
    top2--;
    return value;
}
void display(){
    if(top1==-1){
        printf("\nQueue is empty.");
    }
    else{
        printf("\nDisplay of Queue");
        for(int i=0 ; i<=top1 ; i++){
            printf("\n%d",s1[i]);
        }
    }

   }
int main(){
    int choice,data;
    while(1){
        printf("\nWhich operation do you want to perform:\n");
        printf("1.Enque Element\n2.Dequeue Element\n3.Display Queue\n4.Quit    :");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        printf("Enter element to enque:");
        scanf("%d",&data);
        enque(data);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(1);
        }
    }
}
