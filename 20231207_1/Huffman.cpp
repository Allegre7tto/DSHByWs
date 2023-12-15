#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void Select(HuffmanTree HT, int index, int &s1, int &s2){
    // 定义一个大小为2的整型数组minW，初始化为0x3f3f3f3f
    int minW[2]={0};
    minW[0]=minW[1]=0x3f3f3f3f;

    // 循环遍历HT数组，从索引为1开始到index
    for (int i=1;i<=index;++i){
        // 如果当前节点的父节点为0，说明是根节点，则执行以下操作
        if (HT[i].parent==0){
            // 如果当前节点的权值小于minW[0]，则执行以下操作
            if (HT[i].weight<minW[0]){
                // 将minW[0]赋值为HT[i].weight，将s2赋值为s1
                minW[1]=minW[0],s2=s1;
                // 将minW[0]赋值为HT[i].weight，将s1赋值为i
                minW[0]=HT[i].weight,s1=i;
            } 
            // 如果当前节点的权值大于等于minW[0]但小于minW[1]，则执行以下操作
            else if (HT[i].weight<minW[1]){
                // 将minW[1]赋值为HT[i].weight，将s2赋值为i
                minW[1]=HT[i].weight,s2=i;
            }
        }
    }
}

void CreateHuffmanTree(HuffmanTree &HT,int n){
    if (n<=1)
        return ;
    int m=2*n-1;
    HT = new HTNode[m+1];
    for (int i=1;i<=m;++i){
        HT[i].parent=0,HT[i].lchild=0,HT[i].rchild=0;
    }
    cout << "请输入叶子结点的权值:" <<endl;
    for (int i=1;i<=n;++i){
        cin >> HT[i].weight;
    }
    for (int i=n+1;i<=m;++i){
        int s1=0,s2=0;
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i,HT[s2].parent=i;
        HT[i].lchild=s1,HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n){
    HC = new char*[n+1];
    char* cd = new char[n];
    cd[n-1]='\0';
    for (int i=1;i<=n;++i){
        int start=n-1,c=i,f=HT[i].parent;
        while (f!=0){
            --start;
            if (HT[f].lchild==c)
                cd[start]='0';
            else
                cd[start]='1';
            c=f,f=HT[f].parent;
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
    } 
    delete cd;
}

int main()
{
    HuffmanTree HT;
    int n=0;
    cout << "请输入叶子结点的个数:" ;
    cin >> n;
    CreateHuffmanTree(HT,n);
    HuffmanCode HC;
    CreateHuffmanCode(HT,HC,n);
    for (int i=1;i<=n;i++)
        cout << HT[i].weight << "的权值为:" << HC[i] <<endl;
    delete HT;
    return 0;
}