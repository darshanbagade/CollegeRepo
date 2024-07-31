//Call by Value
#include<stdio.h>
int Add(int a,int b){
    return (a+b);
}
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int sum = Add(a, b);
    printf("Addition: %d\n", sum);
    return 0;
}

