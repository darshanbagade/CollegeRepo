//Prime numbers in range
#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the range (a->b) :");
    scanf("%d %d",&a,&b);
    //i denotes the numbers form range a to b
    for(int i=a; i<=b; i++)
    {
        int counter=0;
        if(i==1){
            continue;
        }
        for(int k=2; k*k<=i ; k++){
            if(i%k==0){
                counter=1;
            }
        }
        //counter=0 means prime number
        if(counter==0){
            printf("%d ",i);
        }
    }

}
