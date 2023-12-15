//用顺序表实现
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAXSIZE=1000;

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

struct Qarray{
    Book* element;
    int size=0;
};

int build_array(Qarray &a){
    a.element = new Book[MAXSIZE];
    if (!a.element){
        return 1;
    } 
    a.size=0;
    return 0;
}

int read_data(Qarray &a,string filename){
    ifstream in(filename);
    int p=0;
    if (in){
        string title1,title2,title3;
        in >> title1 >> title2 >> title3;
        while (!in.eof()){
            in >> a.element[a.size].id >> a.element[a.size].name >> a.element[a.size].price;
            ++a.size;
        }
    }
    else
        p=1;
    in.close();
    return p;
}

Book* get_element(Qarray &a,int index){
    if (index<1 || index>a.size){
        return nullptr;
    }
    return &a.element[index-1];
}

Book* find_element(Qarray &a,string n){
    for(int i=0;i<a.size;i++){
        if (a.element[i].name==n){
            return &a.element[i];
        }
    }
    return nullptr;
}

int insert_element(Qarray &a,int index,Book* b){
    if ((index<1) || (index>a.size)){
        return -1;
    }
    if (a.size==MAXSIZE){
        return 1;
    }
    for (int i=a.size-1;i>=index-1;i--){
        a.element[i+1]=a.element[i];
    }
    a.element[index-1]=*b;
    ++a.size;
    return 0;
}

int remove_element(Qarray &a,int index){
    if (index<1 || index>a.size){
        return -1;
    }
    for (int i=index;i<=a.size-1;i++)
        a.element[i-1]=a.element[i];
    --a.size;
    return 0;
}

void output_array(Qarray a){
    for (int i=0;i<a.size;i++)
        a.element[i].output();
}

int main()
{
    Qarray myarray;
    int choice=1;
    while (choice){
        cin >> choice;
        if (choice==1){
            if (build_array(myarray)==0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice==2){
            string address="./book.txt";
            if (read_data(myarray,address) == 0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice==3){
            int index;
            cout << "input index:" ;
            cin >> index;
            cout <<endl;
            Book* b=get_element(myarray,index);
            if (b!=nullptr){
                b->output();
            }
            else{
                cout << "not exist" <<endl;
            }
            continue;
        }
        if (choice==4){
            string name;
            cout << "input name:" ;
            cin >> ws; getline(cin,name);
            Book* b=find_element(myarray,name);
            if (b!=nullptr)
                b->output();
            else
                cout << "not exist" <<endl;
            continue;
        }
        if (choice==5){
            int index;
            Book b;
            cout << "input index:" ;
                cin >> index;
            cout << "input the book's message" <<endl;
            cout << "input id:";
                cin >> ws;getline(cin,b.id);
            cout << "input name:";
                cin >> ws;getline(cin,b.name);
            cout << "input price";
                cin >> b.price;
            if ((insert_element(myarray,index,&b))==0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice==6){
            int index;
            cout << "input index:";
                cin >> index;
            if (remove_element(myarray,index)==0)
                cout << "Success" <<endl;
            else
                cout << "Fail" <<endl;
            continue;
        }
        if (choice==7){
            output_array(myarray);
            continue;
        }
    }
}