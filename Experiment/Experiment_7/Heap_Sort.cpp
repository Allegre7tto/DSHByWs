#include <iostream>
#include <cstdlib>
using namespace std;

void HeapAdjust(int arr[],int s,int m){
    int rc=arr[s];
    for (int j=2*s;j<=m;j*=2){
        if(j<m && arr[j]<arr[j+1]) 
            ++j;
        if(rc>=arr[j]) 
            break;
        arr[s]=arr[j];
        s=j;
    }
    arr[s]=rc;
}

void CreateHeap(int arr[],int n){
    for(int i=n/2;i>0;--i)
        HeapAdjust(arr,i,n);
}

void HeapSort(int arr[],int n){
    CreateHeap(arr,n);
    for(int i=n;i>1;--i){
        swap(arr[i],arr[1]);
        HeapAdjust(arr,1,i-1);
    }
}

int main()
{
    const int n = 5*1e4;
    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%1000;
    for (int i=0;i<n;i++) 
        cout << arr[i] << " ";
    cout <<endl;
    HeapSort(arr,n);
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    return 0;
}