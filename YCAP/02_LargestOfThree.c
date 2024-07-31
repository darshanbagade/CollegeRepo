
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter three numbers:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b){
        if(a>c){
            printf("%d is largest.",a);
        }
        else{
            printf("%d is largest.",c);
        }
    }
    else if(b>c)
    {
        printf("%d is the the largest number",b);
    }
    else
    {
            printf("%d is the the largest number",c);
    }

    return 0;
}
