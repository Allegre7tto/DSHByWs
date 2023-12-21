#include <iostream>
using namespace std;

const long long MAXSIZE = 1000;

typedef struct{
    int key;
} ElemType;

typedef struct{
    ElemType *R;
    int length;
} SSTable;

int Build_Seq(SSTable &ST){
    int i;
    ST.R = new ElemType[MAXSIZE];
    cout << "请输入元素个数：" ;
    cin >> ST.length;
    if(!ST.R) 
        return 1;
    for(i = 1; i <= ST.length; ++i){
        cin >> ST.R[i].key;
    }
    return 0;
}

int Search_Seq(SSTable ST, int key){
    int mid=0, low=1, high=ST.length;
    cout << "查找" << key << "所比较的关键字:" ;
    while(low <= high){
        mid = (low + high) / 2;
        cout << ST.R[mid].key << " ";
        if(ST.R[mid].key == key){
            cout <<endl;
            return mid;
        }
        else if(ST.R[mid].key > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout <<endl;
    return 0;
}

int main()
{
    SSTable ST;
    int key,tmp=0;
    Build_Seq(ST);
    cout << "请输入要查找的元素:" ;
    cin >> key;
    cout << "折半查找:" <<endl;
    tmp=Search_Seq(ST, key);
    cout << "元素" << key << "的位置是" << tmp << endl;
    return 0;
}