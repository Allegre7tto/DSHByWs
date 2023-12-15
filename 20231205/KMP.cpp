#include <iostream>
#include <fstream>
using namespace std;

const long long MAXSIZE = 1e3;

ifstream in("virus_detection.txt");

typedef struct {
    char *ch;
    int length;
}SqStr;

int Initstr(SqStr &S){
    S.ch = new char[MAXSIZE];
    if (!S.ch)
        return 1;
    S.length = 0;
    return 0;
}

int GetElem(SqStr S,int index,char &e){
    if (index<1 || index>S.length+1)
        return 1;
    e=S.ch[index-1];
    return 0;
} 

int Strinsert(SqStr &S,int index,char e){
    if (index<1 || index>S.length+1)
        return 1;
    if (S.length==MAXSIZE)
        return 1;
    for (int i=S.length-1;i>=index-1;i--)
        S.ch[i+1]=S.ch[i];
    S.ch[index-1]=e; 
    ++S.length;
    return 0;
}

int Concat(SqStr &S,SqStr t){
    for (int i=1;i<=t.length;i++){
        char tmp;
        GetElem(t,i,tmp);
        Strinsert(S,S.length+1,tmp);
    }
    return 0;
}

int subStr(SqStr &S,SqStr t,int index,int len){
    for (int i=index;i<=min(t.length,index+len-1);i++){
        char tmp;
        GetElem(t,i,tmp);
        Strinsert(S,S.length+1,tmp);
    }
}

int inputStr(SqStr &S){
    in >> S.ch;
    int cnt;
    for (cnt=0;S.ch[cnt]!=0;cnt++);
    S.length=cnt;
    return 0;
}

int outputStr(SqStr S){
    for (int i=1;i<=S.length;i++){
        char tmp;
        GetElem(S,i,tmp);
        cout << tmp ;
    }
    //cout <<endl;
}

bool kmp(SqStr pattern,SqStr text){
    SqStr cur;
    Initstr(cur);
    Concat(cur,pattern);
    Strinsert(cur,cur.length+1,'#');
    Concat(cur,text);
    int next[cur.length]={0};
    for (int i=1;i<cur.length;i++){
        int tar = next[i-1];
        while (tar > 0 && cur.ch[i] != cur.ch[tar])
            tar = next[tar-1];
        if (cur.ch[i]==cur.ch[tar])
            tar++;
        next[i]=tar;
    }
    for (int i = pattern.length+1;i<=pattern.length+text.length;i++){
        if (next[i]==(pattern.length))
            return 1;
    }
    return 0;
}

int main()
{
    //ifstream in("virus_detection.txt");
    if (!in){
        cout << "未找到文件" <<endl;
        return 0;
    }
    while (!in.eof()){
        SqStr s1,s2;
        int res=0;
        Initstr(s1),Initstr(s2);
        inputStr(s1),inputStr(s2);
        outputStr(s1);
        cout << " ";
        outputStr(s2);
        cout << " ";
        Concat(s1,s1);
        for (int i=1;i<=(s1.length/2);i++){
            SqStr tmp;
            Initstr(tmp);
            subStr(tmp,s1,i,(s1.length/2));
            if (kmp(tmp,s2)){
                res=1;
                break;
            }
        }
        if (res)
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
    return 0;
}