//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int p = partition(arr,low,high); //p is partitioning index, arr[p] is now  at right place
            quickSort(arr,low,p); //separately sorts element before
            quickSort(arr,p+1,high);
        }
        return;
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
            int pivot = arr[l]; // first element is pivot
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            ++i;
        } while (arr[i] < pivot); // l to i must be smaller than =  pivot
        do
        {
            j--;
        } while (arr[j] > pivot); // j to h must be greater than =   pivot
        if (i >= j)               // i and j crossed each other
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
    return i+1;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends