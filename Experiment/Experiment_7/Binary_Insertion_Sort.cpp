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
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        int l = 0, r = i-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]>key)
                r = mid-1;
            else
                l = mid+1;
        }
        while(j>=l){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    return 0;
}