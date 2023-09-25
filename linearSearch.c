#include<stdio.h>
int main(){
    int array[10],n=10,key;

    for(int i=0;i<n;i++){
        printf("enter the number %i: ",i+1);
        scanf("%i",&array[i]);
    }
    printf("Enter key : ");
    scanf("%i",&key);

    for(int i=0;i<n;i++){
        if(key==array[i]){
            printf("found at : %i",i);
            return 0;
        }
    }
}