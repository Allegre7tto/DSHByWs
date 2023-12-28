#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int n = 5*1e4;
    int arr[n];
    for(int i=0;i<n;i++) 
        arr[i] = rand()%1000;
    for (int i=0;i<n;i++) 
        cout << arr[i] << " ";
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
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    return 0;
}