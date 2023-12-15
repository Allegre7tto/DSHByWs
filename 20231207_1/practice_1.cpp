#include <iostream>
using namespace std;

typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T){
    char ch=0;
    cin >> ch;
    if (ch!='#'){
        T = new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    else
        T = nullptr;
    return;
}

void InOrderTraverse(BiTree T){
    if (T){
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

void Copy(BiTree T,BiTree &NewT){
    if (T!=nullptr){
        NewT = new BiTNode;
        NewT->data=T->data;
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
    else
        NewT = nullptr;
}

int Depth(BiTree T){
    if (T==nullptr)
        return 0;
    int m=Depth(T->lchild);
    int n=Depth(T->rchild);
    return (m>n)?(m+1):(n+1);
}

int NodeCount(BiTree T){
    if (T==nullptr)
        return 0;
    return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int main()
{
    BiTree mytree;
    cout << "请输入先序遍历:" ;
    CreateBiTree(mytree);
    InOrderTraverse(mytree);
    cout <<endl;
    BiTree Newt;
    Copy(mytree,Newt);
    cout << Depth(Newt) <<endl;
    cout << NodeCount(Newt) <<endl;
    return 0;
}