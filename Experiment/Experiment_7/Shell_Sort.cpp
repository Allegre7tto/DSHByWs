//希尔排序
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
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int key = arr[i];
            int j = i-gap;
            while(j>=0 && arr[j]>key){
                arr[j+gap] = arr[j];
                j-=gap;
            }
            arr[j+gap] = key;
        }
    }
    for(int i=0;i<n;i+=200) 
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << endl << "希尔排序程序执行时间: " << diff.count() << " 秒" << endl;
    return 0;
}