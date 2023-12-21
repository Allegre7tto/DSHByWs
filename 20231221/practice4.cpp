#include <iostream>
using namespace std;

#define m 16
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
    cout << "请输入哈希表的元素个数:";
    int len;
    cin >> len;
    for (int i=1;i<=len;++i){
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