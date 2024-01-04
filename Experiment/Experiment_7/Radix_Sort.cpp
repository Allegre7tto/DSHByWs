//基数排序
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    const int n = 50;
    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%100;
    /*for (int i=0;i<n;i++) 
        cout << arr[i] << " "; */
    cout <<endl;
    int max = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max = arr[i];
    int exp = 1;
    while(max/exp>0){
        int output[n];
        int count[10] = {0};
        for(int i=0;i<n;i++)
            count[(arr[i]/exp)%10]++;
        for(int i=1;i<10;i++)
            count[i] += count[i-1];
        for(int i=n-1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++)
            arr[i] = output[i];
        exp *= 10;
    }
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << endl << "程序执行时间: " << diff.count() << " 秒" << endl;
    return 0;
}