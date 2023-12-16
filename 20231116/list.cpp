// 用单链表实现
#include <iostream>  // 引入输入输出流库
#include <fstream>  // 引入文件流库
#include <cstring>  // 引入字符串库
using namespace std;  // 使用标准命名空间

// 定义书籍结构体
struct Book{
    string id;  // 书籍的ID
    string name;  // 书籍的名称
    double price;  // 书籍的价格
    void output(){  // 输出书籍信息的函数
        cout << "ISBN:" << id <<endl;  // 输出书籍的ID
        cout << "name:" << name <<endl;  // 输出书籍的名称
        cout << "price:" << price <<endl;  // 输出书籍的价格
    }
};

// 定义链表节点结构体
typedef struct Lnode{
    Book data;  // 节点存储的数据，是一个Book类型的结构体
    struct Lnode *next;  // 指向下一个节点的指针
}LNode,*LinkList;  // LNode是节点类型，LinkList是节点指针类型

// 初始化链表的函数
int InitList_L(LinkList &L){
    L = new LNode;  // 创建一个新的节点
    L->next = nullptr;  // 设置新节点的next指针为null
    return 0;  // 返回0表示初始化成功
}

// 从文件中读取数据的函数
int read_data(LinkList &L,string filename){
    ifstream in(filename);  // 创建一个输入流，用于读取文件
    int re=0;  // 初始化返回值为0
    LNode* p=L;  // 创建一个节点指针，指向链表的头节点
    if (in){  // 如果文件打开成功
        string title1,title2,title3;  // 创建三个字符串，用于存储文件的标题
        in >> title1 >> title2 >> title3;  // 读取文件的标题
        while (!in.eof()){  // 当没有到达文件末尾时，继续循环
            LNode* tmp=new LNode;  // 创建一个新的节点
            in >> tmp->data.id >> tmp->data.name >> tmp->data.price;  // 从文件中读取数据，存入新节点的data字段
            tmp->next=p->next;  // 设置新节点的next指针，使其指向当前节点的下一个节点
            p->next=tmp;  // 设置当前节点的next指针，使其指向新节点
        }
    }
    else  // 如果文件打开失败
        re=1;  // 设置返回值为1
    in.close();  // 关闭文件
    return re;  // 返回结果
}

// 获取链表中指定位置元素的函数
int GetElem_L(LinkList L,int index,Book &b){
    LNode* p=L->next;  // 创建一个节点指针，指向链表的第一个节点
    int i;
    for (i=0;(p && i<index);++i){  // 循环，直到找到指定位置的节点或到达链表末尾
        p=p->next;  // 将指针移动到下一个节点
    }
    if (!p || i>index)  // 如果没有找到指定位置的节点
        return 1;  // 返回1表示失败
    b=p->data;  // 将找到的节点的数据赋值给b
    return 0;  // 返回0表示成功
}

// 在链表中查找指定ID的书籍的函数
LNode *FindElem_L(LinkList L,string b_id){
    LNode* p=L->next;  // 创建一个节点指针，指向链表的第一个节点
    while (p && p->data.id!=b_id)  // 循环，直到找到指定ID的书籍或到达链表末尾
        p=p->next;  // 将指针移动到下一个节点
    return p;  // 返回找到的节点的指针，如果没有找到，返回null
}

// 在链表的指定位置插入元素的函数
int ListInsert_L(LinkList &L,int index,Book b){
    LNode* p=L;  // 创建一个节点指针，指向链表的头节点
    int i;
    // 循环，直到找到指定位置的前一个节点或到达链表末尾
    for (i=0;(p && i<index-1);++i)
        p=p->next;  // 将指针移动到下一个节点
    // 如果没有找到指定位置的前一个节点
    if (!p || i>index-1)
        return 1;  // 返回1表示失败
    LNode* s=new LNode;  // 创建一个新的节点
    s->data=b;  // 将要插入的数据赋值给新节点的data字段
    s->next=p->next;  // 设置新节点的next指针，使其指向当前节点的下一个节点
    p->next=s;  // 设置当前节点的next指针，使其指向新节点
    return 0;  // 返回0表示成功
}

// 在链表的指定位置删除元素的函数
int ListDelete_L(LinkList &L,int index){
    LNode* p=L;  // 创建一个节点指针，指向链表的头节点
    int i;
    // 循环，直到找到指定位置的前一个节点或到达链表末尾
    for (i=0;(p->next && i<index-1);i++)
        p=p->next;  // 将指针移动到下一个节点
    // 如果没有找到指定位置的前一个节点
    if (!(p->next) || i>index-1)
        return 1;  // 返回1表示失败
    LNode* tmp=p->next;  // 创建一个节点指针，指向要删除的节点
    p->next=tmp->next;  // 设置当前节点的next指针，使其指向要删除节点的下一个节点
    delete tmp;  // 删除要删除的节点
    return 0;  // 返回0表示成功
}

// 输出链表中所有元素的函数
void output_list(LinkList L){
    LNode* p=L->next;  // 创建一个节点指针，指向链表的第一个节点
    while (p){  // 当没有到达链表末尾时，继续循环
        p->data.output();  // 调用节点的data字段的output函数，输出节点的数据
        p=p->next;  // 将指针移动到下一个节点
    }
}

int main()
{
    LinkList mylist;  // 创建一个链表
    int choice=1;  // 初始化用户的选择为1
    while (choice){  // 当用户的选择不为0时，继续循环
        cout << "input:";  // 提示用户输入
        cin >> choice;  // 获取用户的输入
        if (choice == 0)  // 如果用户的选择为0
            break;  // 结束循环
        if (choice == 1){  // 如果用户的选择为1
            // 初始化链表
            if (InitList_L(mylist)==0)  // 如果初始化成功
                cout << "Sucess"<<endl;  // 输出"Sucess"
            else  // 如果初始化失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice == 2){  // 如果用户的选择为2
            string address="./book.txt";  // 设置文件地址
            // 从文件中读取数据
            if (read_data(mylist,address) == 0)  // 如果读取成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果读取失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice == 3){  // 如果用户的选择为3
            int index=0;  // 初始化索引为0
            cout << "input index:" ;  // 提示用户输入索引
            cin >> index ;  // 获取用户输入的索引
            Book b;  // 创建一个Book类型的变量
            // 获取链表中指定位置的元素
            if (GetElem_L(mylist,index,b)==0)  // 如果获取成功
                b.output();  // 输出元素的信息
            else  // 如果获取失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice == 4){  // 如果用户的选择为4
            string id;  // 创建一个字符串，用于存储书籍的ID
            cout << "input the ISBN of the book:" ;  // 提示用户输入书籍的ID
            cin >> ws; getline(cin,id);  // 获取用户输入的书籍的ID
            // 在链表中查找指定ID的书籍
            LNode* node = FindElem_L(mylist,id);
            if (node!=nullptr)  // 如果找到了书籍
                node->data.output();  // 输出书籍的信息
            else  // 如果没有找到书籍
                cout << "not found" <<endl;  // 输出"not found"
            continue;  // 进入下一次循环
        }
        if (choice == 5){  // 如果用户的选择为5
            Book b;  // 创建一个Book类型的变量
            cout << "input the message of the book" <<endl;  // 提示用户输入书籍的信息
            cout << "input the ISBN:" ;  // 提示用户输入书籍的ID
            cin >> ws; getline(cin,b.id);  // 获取用户输入的书籍的ID
            cout << "input the name:" ;  // 提示用户输入书籍的名称
            cin >> ws; getline(cin,b.name);  // 获取用户输入的书籍的名称
            cout << "input the price:" ;  // 提示用户输入书籍的价格
            cin >> b.price;  // 获取用户输入的书籍的价格
            int index;  // 创建一个整数，用于存储索引
            cout << "input the index to insert:";  // 提示用户输入要插入的位置
            cin >> index;  // 获取用户输入的位置
            // 在链表的指定位置插入元素
            if (ListInsert_L(mylist,index,b)==0)  // 如果插入成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果插入失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice == 6){  // 如果用户的选择为6
            int index;  // 创建一个整数，用于存储索引
            cout << "input the index to delete:";  // 提示用户输入要删除的位置
            cin >> index;  // 获取用户输入的位置
            // 在链表的指定位置删除元素
            if (ListDelete_L(mylist,index)==0)  // 如果删除成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果删除失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice == 7){  // 如果用户的选择为7
            output_list(mylist);  // 输出链表
            continue;  // 进入下一次循环
        }
}