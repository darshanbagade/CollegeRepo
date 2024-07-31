//Darshan Bagade
//Number is Palindrome or not

#include<stdio.h>

//Function for reversing the number
int reverse(int n)
{
    int remainder;
    int rev=0;
    while(n!=0)
    {
       remainder=n%10;
       rev=rev*10+remainder;
       n/=10;
    }
    return rev;
}

int main(){
    int n;
    printf("Enter number:");
    scanf("%d",&n);
    int reverse_num=reverse(n);

    //condition for palindrome
    if(reverse_num==n){
        printf("Is palindrome");
    }
    else{
        printf("Not palindrome");
    }
    printf("\n-------------------");
}
