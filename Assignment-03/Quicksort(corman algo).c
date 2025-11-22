#include<stdio.h>
int partition(int A[],int p,int r);
void swap(int *a,int *b);
void Quicksort(int A[],int p,int r);
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int A[n];
                                                         // space complexcity-O(n)--<log n to n>.
    printf("Enter the array element:");                 // Best case-O(nlogn) if partition done always in the middle means piovt element is median
                                                        // worst case-O(n^2) if the array is already sorted.
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Quicksort(A,0,n-1);
    printf("Sorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Quicksort(int A[],int p,int r)
{
    if(p<r){
    int q=partition(A,p,r);
    Quicksort(A,p,q-1);
    Quicksort(A,q+1,r);
    }
}
int partition(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}