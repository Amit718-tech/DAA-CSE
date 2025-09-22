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
    int low=0;
    int high=n-1;
    while(low<=high)
    {
       int mid=(low+high)/2;
        if(arr[mid]==key){
            printf("Element %d found at position %d",key,mid+1);
            found=1;
            break;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        if(found!=1)
        {
            printf("Element %d is not present in the array.",key);
        }
        return 0;
    }