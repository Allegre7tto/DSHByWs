//使用string标准库实现
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXN = 1e3;

bool kmp(string pattern,string text){
    string cur = pattern + '#' + text;
    int next[cur.length()]={0};
    for (int i=1;i<cur.length();i++){
        int tar = next[i-1];
        while (tar > 0 && cur[i] != cur[tar])
            tar = next[tar-1];
        if (cur[i]==cur[tar])
            tar++;
        next[i]=tar;
    }
    for (int i = pattern.size()+1;i<=pattern.size()+text.size();i++){
        if (next[i]==(pattern.size()))
            return 1;
    }
    return 0;
}

int main()
{
    ifstream in("virus_detection.txt");
    if (!in){
        cout << "未找到文件" <<endl;
        return 0;
    }
    while (!in.eof()){
        int check=0;
        string s1,s2;
        in >> s1 >> s2;
        string tmps=s1+s1;
        for (int i=0;i<s1.length();i++){
            string ts=tmps.substr(i,s1.length());
            //cout << ts <<endl;
            if (kmp(ts,s2)){
                check=1;
                break;
            }
        }
        if (check)
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
    return 0;
}