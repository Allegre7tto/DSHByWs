//归并排序
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
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
    for (int i=left;i<=right;i++)
        arr[i] = res[i];
}

void MergeSort(int arr[],int left,int right)
{
    static int tmp[n]={}; // int tmp[right-left+1
    if (left>right) 
        return;
    if (left==right) {
        tmp[left] = arr[left];
        return;
    }
   
    int mid = (left+right)/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    Merge(arr,tmp,left,mid,right);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%1000;
    /*for (int i=0;i<n;i++) 
        cout << arr[i] << " "; */
    //int res[n];
    cout <<endl;
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i+=200) 
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << endl << "归并排序程序执行时间: " << diff.count() << " 秒" << endl;
    return 0;
}