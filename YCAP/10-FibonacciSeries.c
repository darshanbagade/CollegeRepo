
#include<stdio.h>
int main(){
    int num,;
    printf("Enter value of number:");
    scanf("%d",&num);
    for(int i=num; i>1 ;i--)
    {
        fact=fact*i;
    }
    printf("Factorial : %d",fact);
    printf("\n-----------------");
}
