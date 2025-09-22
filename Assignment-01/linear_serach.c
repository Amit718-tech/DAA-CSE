#include<stdio.h>
int main(){
    int n,key,i,found=0;
    printf("Enetr the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array element:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enetr the key elment to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key){
            printf("key %d is persent at %d position.",key,i);
            found=1;
            break;
        }
    }
    if(found!=1){
        printf("key %d is not present in the array.",key);
    }
    return 0;
}