//快速排序
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void QuickSort(int arr[],int left,int right)
{
    if(left>=right) return;
    int i = left;
    int j = right;
    int key = arr[left];
    while(i<j)
    {
        while(i<j && arr[j]>=key) 
            j--;
        arr[i] = arr[j];
        while(i<j && arr[i]<=key) 
            i++;
        arr[j] = arr[i];
    }
    arr[i] = key;
    QuickSort(arr,left,i-1);
    QuickSort(arr,i+1,right);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    const int n = 5*1e4;
    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%1000;
    /*for (int i=0;i<n;i++) 
        cout << arr[i] << " "; */
    cout <<endl;
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i+=200) 
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << endl << "快速排序程序执行时间: " << diff.count() << " 秒" << endl;
    return 0;
}