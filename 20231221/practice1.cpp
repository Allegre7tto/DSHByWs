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

int Search_Seq0(SSTable ST, int key){
    int i;
    ST.R[0].key = key;
    cout << "查找" << key << "所比较的关键字:" ;
    for(i = ST.length; ST.R[i].key != key; --i){
        cout << ST.R[i].key << " ";
    }
    cout <<endl;
    return i;
}

int Search_Seq1(SSTable ST, int key){
    int i;
    cout << "查找" << key << "所比较的关键字:" ;
    for(i = 1; i <= ST.length && ST.R[i].key != key; ++i){
        cout << ST.R[i].key << " ";
    }
    cout <<endl;
    if(i > ST.length)
        return 0;
    else
        return i;
}

int main()
{
    SSTable ST;
    int key,tmp=0;
    Build_Seq(ST);
    cout << "请输入要查找的元素:" ;
    cin >> key;
    cout << "顺序查找:" <<endl;
    tmp=Search_Seq0(ST, key);
    cout << "元素" << key << "的位置是" << tmp << endl;
    cout << "带监视哨的顺序查找:" <<endl;
    tmp=Search_Seq1(ST, key);
    cout << "元素" << key << "的位置是" << tmp << endl;
    return 0;
}