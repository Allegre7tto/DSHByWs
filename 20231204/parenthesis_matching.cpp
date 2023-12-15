#include <iostream>
using namespace std;

typedef struct Stacknode{
    char data;
    struct Stacknode *next;
}StackNode, *LinkStack;
LinkStack S;

void InitStack(LinkStack &S){
    S=nullptr;
}

bool StackEmpty(LinkStack S){
    if (S==nullptr)
        return true;
    else
        return false;
}

int Push(LinkStack &S, char e){
    StackNode* p = new StackNode;
    if (!p){
        return 1;
    }
    p->data=e;
    p->next=S;
    S=p;
    return 0;
}

int Pop(LinkStack &S,char &e){
    if (S==nullptr){
        return 1;
    }
    e=S->data;
    StackNode* p=S;
    S=S->next;
    delete p;
    return 0;
}

char GetTop(LinkStack S){
    if (S==nullptr)
        return 1;
    else
        return S->data;
}

bool check(char y,char x){
    if (x=='(' && y==')')
        return 1;
    if (x=='{' && y=='}')
        return 1;
    if (x=='[' && y==']')
        return 1;
    return 0;
}

int main()
{
    string str;
    cout << "请输入匹配串:" ;
    cin >> str;
    int res=1;
    for (int i=0;i<str.length()-1;i++){
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
            Push(S,str[i]);
        else{
            char e=0;
            Pop(S,e);
            if (!check(str[i],e)){
                res=0;
                break;
            }
        }
    }
    if (res){
        cout << "True" <<endl;
    }
    else{
        cout << "False" <<endl;
    }
    return 0;
}