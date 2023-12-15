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

typedef struct DuLnode{
    Book data;
    struct DuLnode *prior;
    struct DuLnode *next;
}DuLNode, *DuLinkList;

int InitList_L(DuLinkList &L){
    L = new DuLNode;
    L->next = nullptr, L->prior = nullptr;
    return 0;
}

int read_data(DuLinkList &L,string filename){
    ifstream in(filename);
    int re=0;
    DuLNode* p=L;
    if (in){
        string title1,title2,title3;
        in >> title1 >> title2 >> title3;
        while (!in.eof()){
            DuLNode* tmp=new DuLNode;
            in >> tmp->data.id >> tmp->data.name >> tmp->data.price;
            tmp->next=p->next;
            tmp->prior=p;
            p->next=tmp;
        }
    }
    else
        re=1;
    in.close();
    return re;
}

DuLNode* GetElem_L(DuLinkList L,int index){
    DuLNode* p=L->next;
    int i;
    for (i=0;(p && i<index);++i){
        p=p->next;
    }
    if (!p || i>index)
        return nullptr;
    return p;
}

DuLNode *FindElem_L(DuLinkList L,string b_id){
    DuLNode* p=L->next;
    while (p && p->data.id!=b_id)
        p=p->next;
    return p;
}

int ListInsert_L(DuLinkList &L,int index,Book b){
    DuLNode* p=GetElem_L(L,index-1);
    if (!(p))
        return 1;
    DuLNode* s=new DuLNode;
    s->data=b;
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return 0;
}

int ListDelete_L(DuLinkList &L,int index){
    DuLNode* p=GetElem_L(L,index);
    if (!p)
        return 1;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
    return 0;
}

void output_list(DuLinkList L){
    DuLNode* p=L->next;
    while (p){
        p->data.output();
        p=p->next;
    }
}

int main()
{
    DuLinkList mylist;
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
            DuLNode* tmp=GetElem_L(mylist,index);
            if (tmp!=nullptr)
                tmp->data.output();
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice == 4){
            string ISBN;
            cout << "input the ISBN of the book:" ;
                cin >> ISBN;
            DuLNode* tmp = FindElem_L(mylist,ISBN);
            if (tmp!=nullptr)
                tmp->data.output();
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
    return 0;
}