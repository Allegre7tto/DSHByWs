// 用顺序表实现
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAXSIZE=1000;  // 定义最大数组大小

// 定义书籍结构体
struct Book{
    string id;  // 书籍ID
    string name;  // 书籍名称
    double price;  // 书籍价格
    void output(){  // 输出书籍信息的函数
        cout << "ISBN:" << id <<endl;
        cout << "name:" << name <<endl;
        cout << "price:" << price <<endl;
    }
};

// 定义顺序表结构体
struct Qarray{
    Book* element;  // 书籍元素数组
    int size=0;  // 顺序表当前大小
};

// 构建顺序表的函数
int build_array(Qarray &a){
    a.element = new Book[MAXSIZE];  // 分配内存
    if (!a.element){  // 如果内存分配失败，返回1
        return 1;
    } 
    a.size=0;  // 初始化顺序表大小为0
    return 0;  // 成功返回0
}

// 从文件中读取数据的函数
int read_data(Qarray &a,string filename){
    ifstream in(filename);  // 打开文件
    int p=0;
    if (in){  // 如果文件打开成功
        string title1,title2,title3;
        in >> title1 >> title2 >> title3;  // 读取文件头
        while (!in.eof()){  // 当未到达文件末尾时
            // 读取一行数据，存入顺序表
            in >> a.element[a.size].id >> a.element[a.size].name >> a.element[a.size].price;
            ++a.size;  // 顺序表大小加1
        }
    }
    else
        p=1;  // 如果文件打开失败，返回1
    in.close();  // 关闭文件
    return p;  // 返回结果
}

// 获取指定位置元素的函数
Book* get_element(Qarray &a,int index){
    if (index<1 || index>a.size){  // 如果索引无效，返回空指针
        return nullptr;
    }
    return &a.element[index-1];  // 返回指定位置的元素
}

// 查找指定元素的函数
Book* find_element(Qarray &a,string n){
    for(int i=0;i<a.size;i++){  // 遍历顺序表
        if (a.element[i].name==n){  // 如果找到匹配的元素，返回该元素
            return &a.element[i];
        }
    }
    return nullptr;  // 如果未找到匹配的元素，返回空指针
}

// 在指定位置插入元素的函数
int insert_element(Qarray &a,int index,Book* b){
    if ((index<1) || (index>a.size)){  // 如果索引无效，返回-1
        return -1;
    }
    if (a.size==MAXSIZE){  // 如果顺序表已满，返回1
        return 1;
    }
    // 将指定位置及其后的元素后移一位
    for (int i=a.size-1;i>=index-1;i--){
        a.element[i+1]=a.element[i];
    }
    a.element[index-1]=*b;  // 在指定位置插入新元素
    ++a.size;  // 顺序表大小加1
    return 0;  // 成功返回0
}

// 删除指定位置元素的函数
int remove_element(Qarray &a,int index){
    if (index<1 || index>a.size){  // 如果索引无效，返回-1
        return -1;
    }
    // 将指定位置后的元素前移一位
    for (int i=index;i<=a.size-1;i++)
        a.element[i-1]=a.element[i];
    --a.size;  // 顺序表大小减1
    return 0;  // 成功返回0
}

// 输出顺序表的函数
void output_array(Qarray a){
    for (int i=0;i<a.size;i++)  // 遍历顺序表
        a.element[i].output();  // 输出每个元素
}

int main()
{
    Qarray myarray;  // 创建一个顺序表
    int choice=1;  // 初始化用户选择为1
    while (choice){  // 当用户选择非0时，继续循环
        cin >> choice;  // 获取用户选择
        if (choice==1){  // 如果用户选择1
            // 构建顺序表
            if (build_array(myarray)==0)  // 如果构建成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果构建失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice==2){  // 如果用户选择2
            string address="./book.txt";  // 设置文件地址
            // 从文件中读取数据
            if (read_data(myarray,address) == 0)  // 如果读取成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果读取失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice==3){  // 如果用户选择3
            int index;  // 定义索引
            cout << "input index:" ;  // 提示用户输入索引
            cin >> index;  // 获取用户输入的索引
            cout <<endl;
            // 获取指定位置的元素
            Book* b=get_element(myarray,index);
            if (b!=nullptr){  // 如果元素存在
                b->output();  // 输出元素
            }
            else{  // 如果元素不存在
                cout << "not exist" <<endl;  // 输出"not exist"
            }
            continue;  // 进入下一次循环
        }
        if (choice==4){  // 如果用户选择4
            string name;  // 定义名称
            cout << "input name:" ;  // 提示用户输入名称
            cin >> ws; getline(cin,name);  // 获取用户输入的名称
            // 查找指定元素
            Book* b=find_element(myarray,name);
            if (b!=nullptr)  // 如果元素存在
                b->output();  // 输出元素
            else  // 如果元素不存在
                cout << "not exist" <<endl;  // 输出"not exist"
            continue;  // 进入下一次循环
        }
        if (choice==5){  // 如果用户选择5
            int index;  // 定义索引
            Book b;  // 创建一个书籍对象
            cout << "input index:" ;  // 提示用户输入索引
            cin >> index;  // 获取用户输入的索引
            cout << "input the book's message" <<endl;  // 提示用户输入书籍信息
            cout << "input id:";  // 提示用户输入ID
            cin >> ws;getline(cin,b.id);  // 获取用户输入的ID
            cout << "input name:";  // 提示用户输入名称
            cin >> ws;getline(cin,b.name);  // 获取用户输入的名称
            cout << "input price";  // 提示用户输入价格
            cin >> b.price;  // 获取用户输入的价格
            // 在指定位置插入元素
            if ((insert_element(myarray,index,&b))==0)  // 如果插入成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果插入失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice==6){  // 如果用户选择6
            int index;  // 定义索引
            cout << "input index:";  // 提示用户输入索引
            cin >> index;  // 获取用户输入的索引
            // 删除指定位置的元素
            if (remove_element(myarray,index)==0)  // 如果删除成功
                cout << "Success" <<endl;  // 输出"Success"
            else  // 如果删除失败
                cout << "Fail" <<endl;  // 输出"Fail"
            continue;  // 进入下一次循环
        }
        if (choice==7){  // 如果用户选择7
            output_array(myarray);  // 输出顺序表
            continue;  // 进入下一次循环
        }
    }
}