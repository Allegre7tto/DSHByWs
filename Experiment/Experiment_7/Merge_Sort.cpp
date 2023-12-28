#include <iostream>
#include <cstdlib>
using namespace std;

const int n = 5*1e4;

void Merge(int arr[],int res[],int left,int mid,int right)
{
    int i = left,j = mid+1,k = left;
    while (i<=mid && j<=right){
        if (arr[i]<=arr[j])
            res[k++] = arr[i++];
        else
            res[k++] = arr[j++];
    }
    while (i<=mid)
        res[k++] = arr[i++];
    while (j<=right)
        res[k++] = arr[j++];
}

void MergeSort(int arr[],int res[],int left,int right)
{
    if (left>right) 
        return;
    if (left==right) {
        res[left] = arr[left];
        return;
    }
    int tmp[n]; // int tmp[right-left+1
    int mid = (left+right)/2;
    MergeSort(arr,tmp,left,mid);
    MergeSort(arr,tmp,mid+1,right);
    Merge(tmp,res,left,mid,right);
}

int main()
{
    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%1000;
    for (int i=0;i<n;i++) 
        cout << arr[i] << " ";
    int res[n];
    cout <<endl;
    MergeSort(arr,res,0,n-1);
    for(int i=0;i<n;i++) 
        cout << res[i] << " ";
    return 0;
}