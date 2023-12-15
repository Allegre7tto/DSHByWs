//用单链表实现
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Book{
    string id;
    string name;
    double price;
    void output(){
        cout << "ISBN:" << id <<endl;
        cout << "name:" << name <<endl;
        cout << "price:" << price <<endl;
    }
};

typedef struct Lnode{
    Book data;
    struct Lnode *next;
}LNode,*LinkList;

int InitList_L(LinkList &L){
    L = new LNode;
    L->next = nullptr;
    return 0;
}

int read_data(LinkList &L,string filename){
    ifstream in(filename);
    int re=0;
    LNode* p=L;
    if (in){
        string title1,title2,title3;
        in >> title1 >> title2 >> title3;
        while (!in.eof()){
            LNode* tmp=new LNode;
            in >> tmp->data.id >> tmp->data.name >> tmp->data.price;
            tmp->next=p->next;
            p->next=tmp;
        }
    }
    else
        re=1;
    in.close();
    return re;
}

int GetElem_L(LinkList L,int index,Book &b){
    LNode* p=L->next;
    int i;
    for (i=0;(p && i<index);++i){
        p=p->next;
    }
    if (!p || i>index)
        return 1;
    b=p->data;
    return 0;
}

LNode *FindElem_L(LinkList L,string b_id){
    LNode* p=L->next;
    while (p && p->data.id!=b_id)
        p=p->next;
    return p;
}

int ListInsert_L(LinkList &L,int index,Book b){
    LNode* p=L;
    int i;
    for (i=0;(p && i<index-1);++i)
        p=p->next;
    if (!p || i>index-1)
        return 1;
    LNode* s=new LNode;
    s->data=b;
    s->next=p->next;
    p->next=s;
    return 0;
}

int ListDelete_L(LinkList &L,int index){
    LNode* p=L;
    int i;
    for (i=0;(p->next && i<index-1);i++)
        p=p->next;
    if (!(p->next) || i>index-1)
        return 1;
    LNode* tmp=p->next;
    p->next=tmp->next;
    delete tmp;
    return 0;
}

void output_list(LinkList L){
    LNode* p=L->next;
    while (p){
        p->data.output();
        p=p->next;
    }
}

int main()
{
    LinkList mylist;
    int choice=1;
    while (choice){
        cout << "input:";
        cin >> choice;
        if (choice == 0)
            break;
        if (choice == 1){
            if (InitList_L(mylist)==0)
                cout << "Sucess"<<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 2){
            string address="./book.txt";
            if (read_data(mylist,address) == 0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 3){
            int index=0;
            cout << "input index:" ;
            cin >> index ;
            Book b;
            if (GetElem_L(mylist,index,b)==0)
                b.output();
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 4){
            string id;
            cout << "input the ISBN of the book:" ;
            cin >> ws; getline(cin,id);
            LNode* node = FindElem_L(mylist,id);
            if (node!=nullptr)
                node->data.output();
            else
                cout << "not found" <<endl;
            continue;
        }
        if (choice == 5){
            Book b;
            cout << "input the message of the book" <<endl;
            cout << "input the ISBN:" ;
                cin >> ws; getline(cin,b.id);
            cout << "input the name:" ;
                cin >> ws; getline(cin,b.name);
            cout << "input the price:" ;
                cin >> b.price;
            int index;
            cout << "input the index to insert:";
                cin >> index;
            if (ListInsert_L(mylist,index,b)==0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 6){
            int index;
            cout << "input the index to delete:";
            cin >> index;
            if (ListDelete_L(mylist,index)==0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 7){
            output_list(mylist);
            continue;
        }
    } 
}