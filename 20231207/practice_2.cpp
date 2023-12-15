//带头节点的中序线索二叉树
#include <iostream>
using namespace std;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag;
}BiThrNode,*BiThrTree;

void CreateBiTree(BiThrTree &T){
    char ch=0;
    cin >> ch;
    if (ch!='#'){
        T = new BiThrNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    else
        T = nullptr;
    return;
}

void InOrderTraverse(BiThrTree T){
    if (T){
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

void InThreading(BiThrTree p,BiThrTree& pre){
    if (p){
        InThreading(p->lchild,pre);
        if (!p->lchild){
            p->LTag=1;
            p->lchild=pre;
        }
        else
            p->LTag=0;
        if (!pre->rchild){
            pre->RTag=1;
            pre->rchild=p;
        }
        else
            p->RTag=0;
        pre = p;
        InThreading(p->rchild,pre);
    }
}

void InOrderThreading(BiThrTree &Thrt,BiThrTree T,BiThrTree& pre){
    Thrt = new BiThrNode;
    Thrt->LTag=0;
    Thrt->RTag=1;
    Thrt->rchild=Thrt;
    if (!T)
        Thrt->lchild=Thrt;
    else{
        Thrt->lchild=T;
        pre=Thrt;
        InThreading(T,pre);
        pre->rchild=Thrt;
        pre->RTag=1;
        Thrt->rchild=pre;
    }
}

void InOrderTraverse_Thr(BiThrTree T){
    BiThrNode* p=T->lchild;
    while (p!=T){
        while (p->LTag==0)
            p=p->lchild;
        cout << p->data;
        while (p->RTag==1 && p->rchild!=T){
            p=p->rchild;
            cout << p->data;
        }
        p=p->rchild;
    }
    delete p;
}

int main()
{
    BiThrTree myt;
    cout << "请输入先序遍历:" ;
    CreateBiTree(myt);
    InOrderTraverse(myt);
    cout <<endl;
    BiThrTree pre = new BiThrNode;
    pre->rchild=nullptr;
    BiThrTree myThrt;
    InOrderThreading(myThrt,myt,pre);
    InOrderTraverse_Thr(myThrt);
    cout <<endl;
    return 0;
}