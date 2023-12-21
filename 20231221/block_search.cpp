#include <iostream>
#include <iomanip>
using namespace std;

const long long MAXSIZE = 1000;
const int blocksize = 5;

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
    cout << "请输入元素:" <<endl;
    for(i = 1; i <= ST.length; ++i){
        cin >> ST.R[i].key;
    }
    return 0;
}

int Block_Search(SSTable ST, int key){
    cout << "查找" << key << "的比较过程如下:" <<endl;
    cout << "(1)在索引表中折半查找:" <<endl;
    int mid=0,low=1,high=ST.length,cnt=0;
    while ((low/blocksize) < (high/blocksize)){
        cout << fixed << setw(2) << "第" << ++cnt << "次比较:"  ;
        mid = (low + high) / 2;
        cout << "在[" << low/blocksize << "," << high/blocksize-1 << "]中比较元素R[" << mid/blocksize << "]:" << ST.R[mid].key << endl;
        if (key <= ST.R[mid].key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << "(2)在对应块中顺序查找" <<endl;
    int index=(low/blocksize)*blocksize;
    cnt=0;
    for (int i=index+1;i<=index+blocksize;++i){
        cout << ST.R[i].key << " ";
        ++cnt;
        if (ST.R[i].key == key){
            cout << "比较" << cnt << "次" << endl;
            return i;
        }
    }
    cout << endl << "比较" << cnt << "次" << endl;
    return 0;
}

int main()
{
    SSTable ST;
    int key,tmp=0;
    Build_Seq(ST);
    cout << "请输入要查找的元素:" ;
    cin >> key;
    cout << "分块查找:" <<endl;
    tmp=Block_Search(ST, key);
    if(tmp)
        cout << "元素" << key << "的地址为:" << tmp << endl;
    else
        cout << "元素" << key << "不存在" << endl;
    return 0;
}