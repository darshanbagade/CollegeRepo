//Darshan Bagade
//Fibonacci Series
#include<stdio.h>
int main(){
    int n,a=0,b=1,c;
    printf("Enter value of n : ");//n-->number of terms
    scanf("%d",&n);
    for(int i=0; i<n ;i++)
    {
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
}
