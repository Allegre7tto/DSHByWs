#include <iostream>
#include <fstream>
using namespace std;

const long long MAXSIZE = 1e3;

typedef struct StackNode{
    string *base;
    string *top;
    int stacksize=0;
}Sqstack;

int InitStack(Sqstack &S){
    S.base = new string[MAXSIZE];
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

int Push(Sqstack &S,string e){
    if (S.top - S.base == S.stacksize){
        return 1;
    }
    *S.top++=e;
    return 0;
}
int Pop(Sqstack &S,string &e){
    if (S.top == S.base){
        return 1;
    }
    e= *--S.top;
    return 0;
}

int GetTop(Sqstack S,string &e){
    if (S.top == S.base)
        return 1;
    e = *(S.top - 1);
    return 0;
}

int main()
{
    Sqstack M,FM;
    InitStack(M);
    InitStack(FM);
    ifstream in("DancePartner.txt");
    if (!in){
        cout << "未找到文件" <<endl;
        return 0;
    }
    while (!in.eof()){
        string name,sex;
        in >> name >> sex;
        if (sex == "M")
            Push(M,name);
        else
            Push(FM,name);
    }
    while (!StackEmpty(M) && !StackEmpty(FM)){
        string Mname="",FMname="";
        Pop(M,Mname);
        Pop(FM,FMname);
        cout << "女:" << FMname << " " << "男:" << Mname <<endl;
    }
    while (!StackEmpty(FM)){
        string FMname="";
        Pop(FM,FMname);
        cout << "女:" << FMname <<endl;
    }
    while (!StackEmpty(M)){
        string Mname="";
        Pop(M,Mname);
        cout << "男:" << Mname <<endl;
    }
    return 0;
}