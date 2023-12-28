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
    for(int i=0;i<n-1;i++){
        int k=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[k])
                k=j;
        }
        swap(arr[i],arr[k]);
    }
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    return 0;
}