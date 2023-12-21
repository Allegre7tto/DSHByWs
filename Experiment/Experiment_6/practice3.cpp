//练习3：二叉排序树
#include <iostream>
using namespace std;

#define ENDFLAG '#'

typedef struct ElemType{
    char key;
} ElemType;

typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree SearchBST(BSTree T, char key){
    if(!T)
        return NULL;
    else if(T->data.key == key)
        return T;
    else if(T->data.key > key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}

void InsertBST(BSTree &T, char key){
    if(!T){
        T = new BSTNode;
        T->data.key = key;
        T->lchild = T->rchild = NULL;
    }
    else if(T->data.key == key)
        return;
    else if(T->data.key > key)
        InsertBST(T->lchild, key);
    else
        InsertBST(T->rchild, key);
}

void DeleteBST(BSTree &T, char key){
    if(!T)
        return;
    else if(T->data.key == key){
        if(!T->lchild && !T->rchild){
            delete T;
            T = NULL;
        }
        else if(!T->lchild){
            BSTree p = T;
            T = T->rchild;
            delete p;
        }
        else if(!T->rchild){
            BSTree p = T;
            T = T->lchild;
            delete p;
        }
        else{
            BSTree p = T->lchild;
            while(p->rchild)
                p = p->rchild;
            T->data.key = p->data.key;
            DeleteBST(T->lchild, p->data.key);
        }
    }
    else if(T->data.key > key)
        DeleteBST(T->lchild, key);
    else
        DeleteBST(T->rchild, key);
}

void CreateBST(BSTree &T){
    T = NULL;
    char key;
    cout << "请输入有序二叉树的元素，以" << ENDFLAG << "结束:" ;
    cin >> key;
    while(key != ENDFLAG){
        InsertBST(T, key);
        cin >> key;
    }
}

void InOrderTraverse(BSTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout << T->data.key << " ";
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    BSTree T;
    char key;
    CreateBST(T);
    cout << "当前有序二叉树中序遍历结果为:" ;
    InOrderTraverse(T);
    cout << endl;
    cout << "请输入要查找的元素:" ;
    cin >> key;
    BSTree p = SearchBST(T, key);
    if(p)
        cout << "元素" << key << "的位置是" << p << endl;
    else
        cout << "元素" << key << "不存在" << endl;
    cout << "请输入待删除的元素:" ;
    cin >> key;
    DeleteBST(T, key);
    cout << "删除元素" << key << "后的中序遍历结果为:" ;
    InOrderTraverse(T);
    cout <<endl;
    return 0;
}