//Darshan Bagade
//Reverse number
#include<stdio.h>
int main(){
    int n,rev=0;
    printf("Enter number:");
    scanf("%d",&n);
    int remainder;
    while(n!=0)
    {
       remainder=n%10;
       rev=rev*10+remainder;
       n/=10;
    }
    printf("Reverse number : %d\n",rev);
}
