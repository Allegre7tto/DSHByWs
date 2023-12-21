# 线性结构

## 线性结构的定义

* 若结构是非空有限集，则有且仅有一个开始结点和一个终端结点，并且所有结点都最多只有一个直接前驱和一个直接后继。

## 线性结构的特点

* 只有一个首结点和尾结点；

* 除首尾结点外，其他结点只有一个直接前驱和一个直接后继。

简言之，线性结构反应结点间的逻辑关系是**一对一**的。

线性结构包括线性表、堆栈、队列、字符串、数组等等，其中，最典型、最常用的是**线性表**

# 第二章 线性表

## 2.1 线性表的定义和特点

线性表的定义：由**相同特性**的数据元素构成的**有限序列**

* *同一线性表中的元素必定具有相同特性*

## 2.3 线性表的类型定义

$$ D=\{ a_i\mid a_i\in ElemSet,i=1,2,\ldots,n,n\ge 0 \} $$

## 2.4 线性表的顺序表示和实现

线性表的顺序表示又称为**顺序存储结构**或**顺序映像**

### 顺序存储定义

把**逻辑上相邻**的数据元素存储在**物理上相邻**的存储单元中的存储结构。

### 顺序存储方法

用**一组地址连续**的存储单元一次存储线性表的元素，可通过 **数组V[n]** 来实现

### 顺序表的类型定义

```c++
typedef struct{
    ElemType elem[MAXSIZE];
    int length;
}SqList;
```
### 线性表的重要类型操作

#### 初始化

```c++
//参数用引用
Status InitList_Sq(SqList &L) { //构造一个空的顺序表L
    L.elem=new ElemType[MAXSIZE]; //为顺序表分配空间
    if(!L.elem) 
        exit(OVERFLOW); //存储分配失败
    L.length=0; //空表长度为0
    return OK;
}
//参数用指针
Status InitList_Sq(SqList *L) { //构造一个空的顺序表L
    L->elem=new ElemType[MAXSIZE]; //为顺序表分配空间
    if(! L->elem) 
        exit(OVERFLOW); //存储分配失败
    L->length=0; //空表长度为0
    return OK;
}
```

#### 取值

```c++
int GetElem(SqList L, int i, ElemType &e) {
    //判断i值是否合理，若不合理，返回ERROR
    if (i<1||i>L.length) 
        return ERROR; 
    e=L.elem[i-1]; //第i-1的单元存储着第i个数据
    return OK;
}
```

#### 查找

```c++
int LocateELem(SqList L, ElemType e) {
    for(i=0;i<L.length;i++)
        if(L.elem[i]==e) 
            return i+1; 
    return 0;
}
```

#### 插入

```c++
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    if(i<1 || i>L.length+1) 
        return ERROR; //i值不合法
    if(L.length==MAXSIZE) 
        return ERROR; //当前存储空间已满
    for(j=L.length-1;j>=i-1;j--) 
        L.elem[j+1]=L.elem[j]; //插入位置及之后的元素后移
    L.elem[i-1]=e; //将新元素e放入第i个位置
    ++L.length; //表长增1
    return OK;
}
```

#### 删除

```c++
Status ListDelete_Sq(SqList &L,int i) {
    if((i<1)||(i>L.length)) 
        return ERROR; //i值不合法
    for (j=i;j<=L.length-1;j++) 
        L.elem[j-1]=L.elem[j]; //被删除元素之后的元素前移
    --L.length; //表长减1
    return OK;
}
```

### 顺序表（顺序存储结构）的特点

* 利用数据元素的存储位置来表示线性表中相邻数据元素之间的前后关系，即线性表的**逻辑结构与存储结构一致**

* 在访问线性表时，可以快速地计算出任何一个数据元素地存储地址。因此可以粗略地认为，**访问每个元素所花时间相等**

*这种存取元素的方法被称为**随机存取法***

### 顺序表的优缺点

* 优点：

    * 时间：可以**随机存取**表中任一元素

    * 空间：**存储密度大**

* 缺点：

    * 时间：在插入、删除某一元素时，需要移动大量元素

    * 空间：浪费存储空间，属于静态存储形式，数据元素的个数不能自由扩充

## 线性表的链式表示和实现

线性表的链式表示又称为**非顺序映像**或**链式映像**

### 链式存储结构

结点在存储器中的位置时**任意**的，即**逻辑上相邻的数据结构在物理上不一定相邻**

### 链式存储方法

通过**指针**实现

### 与链式存储有关的术语

* 结点：数据元素的存储映像，有两个域组成：

    * **数据域：** 存储元素数值数据

    * **指针域：** 存储直接后继结点的存储位置

* 链表：n个结点由指针链组成一个链表

* **单链表、循环链表、双链表：**

    * 结点只有一个指针域的链表，称为**单链表**或**线性链表**

    * 首位相接的链表称为**循环链表**

    * 有两个指针域的链表，称为**双链表**

* 头指针、头结点和首元结点

    * **头指针**是指向链表第一个结点的指针

    * **首元结点**是指链表中存储**第一个数据元素**$a_1$的结点

    * **头结点**是在链表的**首元结点之前**附设的一个结点；数据域内只放空表标志和表长等信息

        * 有头结点时，**当头结点的指针域为空**时表示空表

        * 在链表中设置头结点有什么好处？

            1. 便于**首元结点**的处理

            2. 便于**空表和非空表**的统一处理

### 链表（链式存储结构）的特点

* 结点在存储器中的位置时**任意**的，即**逻辑上相邻的数据元素在物理上不一定相邻**

* 访问时只能通过头指针进入链表，并通过每个阶段的指针域向后扫描其余结点，所以寻找第一个结点和最后一个结点所花费的时间不等

*这种存取元素的方法被称为**顺序存储法***

### 单链表的定义和实现

* 单链表是由**表头**唯一确定，因此单链表可以用头指针的名字来命名

* 若头指针名是L，则把链表称为表L

### 单链表的存储结构定义

```c++
typedef struct Lnode {
    ElemType data; //数据域
    struct LNode *next; //指针域
}LNode,*LinkList;
```

* **注意区分指针变量和结点变量两个不同的概念**

    * 指针变量$p$：表示结点地址

    * 结点变量$*p$：表示一个结点

### 单链表基本操作的实现

#### 初始化

```c++
Status InitList_L(LinkList &L){ 
    L=new LNode; 
    L->next=NULL;
    return OK; 
}
```

#### 取值

```c++
//根据位置i获取线性表L中的某个数据元素的内容
Status GetElem_L(LinkList L,int i,ElemType &e){ 
    p=L->next;j=1; //初始化
    while(p && j<i){ //向后扫描，直到p指向第i个元素或p为空
        p=p->next, ++j; 
    } 
    if(!p || j>i)
        return ERROR; //第i个元素不存在
    e=p->data; //取第i个元素
    return OK; 
}
```

#### 查找

```c++
//在线性表L中查找值为e的数据元素
LNode *LocateELem_L (LinkList L，Elemtype e) {
    //返回L中值为e的数据元素的地址，查找失败返回NULL
    p=L->next;
    while(p && p->data!=e) 
        p=p->next; 
    return p; 
}

//在线性表L中查找值为e的数据元素
int LocateELem_L (LinkList L，Elemtype e) {
    //返回L中值为e的数据元素的位置序号，查找失败返回0 
    p=L->next; j=1;
    while(p && p->data!=e) {
        p=p->next, j++;
    } 
    if(p) 
        return j; 
    else 
        return 0;
}
```

#### 插入

```c++
Status ListInsert_L(LinkList &L,int i,ElemType e){ 
    p=L;j=0; 
    while(p&&j<i−1){
        p=p->next, ++j;
    } //寻找第i−1个结点
    if(!p||j>i−1)
        return ERROR; //i大于表长或者小于1 
    s=new LNode; //生成新结点s 
    s->data=e; //将结点s的数据域置为e 
    s->next=p->next; //将结点s插入L中
    p->next=s; 
    return OK; 
}
```

#### 删除

```c++
Status ListDelete_L(LinkList &L,int i,ElemType &e){
    p=L;j=0; 
    while(p->next &&j<i-1) { //寻找第i个结点，并令p指向其前驱
        p=p->next, ++j; 
    }   
    if(!(p->next)||j>i-1) 
        return ERROR; //删除位置不合理
    q=p->next; //临时保存被删结点的地址以备释放
    p->next=q->next; //改变删除结点前驱结点的指针域
    e=q->data; //保存删除结点的数据域
    delete q; //释放删除结点的空间
    return OK; 
}
```

#### 链表的运算时间效率分析

* **查找**：因线性链表只能顺序存取，即在查找时要从头指针找起。查找的时间复杂度为$O(n)$

* **插入和删除**：因线性链表不需要移动元素，只需修改指针。一般情况下时间复杂度为$O(1)$

#### 单链表的建立

* 头插法

```c++
void CreateList_F(LinkList &L,int n){ 
    L=new LNode; 
    L->next=NULL; //先建立一个带头结点的单链表
    for(i=n;i>0;--i){ 
        p=new LNode; //生成新结点p
        cin>>p->data; //输入元素值
        p->next=L->next; //将p插在首结点之前，头结点之后
        L->next=p; 
    } 
}
```

* 尾插法

    * **注意**：*链表的结点顺序与逻辑次序**相同***

```c++
void CreateList_L(LinkList &L,int n){ 
    //正位序输入n个元素的值，建立带表头结点的单链表L 
    L=new LNode; 
    L->next=NULL; 
    r=L; //尾指针r指向头结点
    for(i=0;i<n;++i){ 
        p=new LNode; //生成新结点
        cin>>p->data; //输入元素值
        p->next=NULL; //p结点next域置为NULL
        r->next=p; //将p插入r之后
        r=p; //r指向新的尾结点
    } 
}
```

### 链表的优缺点

* 优点

    * 时间：插入、删除等操作不必移动数据，只需修改链接指针，**修改效率较高**

    * 空间：数据元素的个数可以**自由扩充**

* 缺点

    * 时间：存取效率不高，必须采用**顺序存储**，即存取数据元素时，只能按链表的顺序进行访问

    * 空间：存储密度小