//十进制数转换转换为8进制数
#include <iostream>
using namespace std;

const long long MAXSIZE = 1e3;

typedef struct StackNode{
    int *base;
    int *top;
    int stacksize=0;
}Sqstack;

int InitStack(Sqstack &S){
    S.base = new int[MAXSIZE];
    if (!S.base){
        return 1;
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return 0;
}

bool StackEmpty(Sqstack S){
    if (S.top == S.base)
        return true;
    else
        return false;
}

int StackLength(Sqstack S){
    return S.top-S.base;
}

int ClearStack(Sqstack S){
    if (S.base)
        S.top = S.base;
    return 0;
}

int DestroyStack(Sqstack &S){
    if (S.base){
        delete S.base;
        S.stacksize=0;
        S.base = S.top = nullptr;
    }
    return 0;
}

int Push(Sqstack &S,int e){
    if (S.top - S.base == S.stacksize){
        return 1;
    }
    *S.top++=e;
    return 0;
}
int Pop(Sqstack &S,int &e){
    if (S.top == S.base){
        return 1;
    }
    e= *--S.top;
    return 0;
}

int GetTop(Sqstack S,int &e){
    if (S.top == S.base)
        return 1;
    e = *(S.top - 1);
    return 0;
}
int main()
{
    Sqstack mys;
    InitStack(mys);
    int N;
    cout << "请输入要转换进制的数:" ;
    cin >> N;
    while (N){
        Push(mys,N%8);
        N /= 8;
    }
    while (!StackEmpty(mys)){
        int e;
        Pop(mys,e);
        cout << e ;
    }
    return 0;
}