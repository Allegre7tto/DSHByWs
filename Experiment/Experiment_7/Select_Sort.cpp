//选择排序
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

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
    for(int i=0;i<n-1;i++){
        int k=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[k])
                k=j;
        }
        swap(arr[i],arr[k]);
    }
    for(int i=0;i<n;i+=200) 
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << endl << "选择排序程序执行时间: " << diff.count() << " 秒" << endl;
    return 0;
}