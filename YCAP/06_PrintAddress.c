
#include<stdio.h>
int main(){
    int a=10;
    int *ptr;
    ptr=&a;

    printf("Accessing Address : %p\n",ptr);
    printf("Accessing Value : %d",*ptr);
}
