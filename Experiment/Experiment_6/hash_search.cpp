//实验六：2. 哈希表查找
#include <iostream>
using namespace std;

#define m 13
#define NULLKEY 0

struct HashTable{
    int key;
};

int Hash(int key){
    return key % m;
}

void CreateHash(HashTable HT[], int key){
    int addr = Hash(key);
    while(HT[addr].key != NULLKEY){
        addr = (addr + 1) % m;
    }
    HT[addr].key = key;
}

int SearchHash(HashTable HT[], int key){
    int addr = Hash(key);
    while(HT[addr].key != NULLKEY && HT[addr].key != key){
        cout << "位置" << addr ;
        if (HT[addr].key != key)
            cout << "未找到" << endl;
        else
            cout << "找到" << endl;
        addr = (addr + 1) % m;
    }
    if(HT[addr].key == key)
        return addr;
    else
        return -1;
}

int main()
{
    HashTable HT[m];
    for (int i=1;i<=m;++i){
        HT[i].key = NULLKEY;
    }
    //cout << "请输入哈希表的元素个数:";
    //int len;
    //cin >> len;
    cout << "构建的哈希表为:" <<endl;
    for (int i=1;i<=m;++i){
        int tmp;
        cin >> tmp;
        CreateHash(HT, tmp);
    }
    cout << "请输入要查找的元素:";
    int key;
    cin >> key;
    int addr = SearchHash(HT, key);
    if(addr != -1)
        cout << "元素" << key << "的地址为:" << addr << endl;
    else
        cout << "元素" << key << "不存在" << endl;
    return 0;
}