//练习5：邻接表实现图的广度优先遍历
#include <iostream>
using namespace std;

const long long MAXINT = 32767;
const long long MAXNUM = 100;

typedef char VerTexType;
typedef int OtherInfo;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo info;
} ArcNode;

typedef struct VNode {
    VerTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAXNUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

typedef struct {
    OtherInfo *base;
    int front, rear;
} sqQueue;

void InitQueue(sqQueue &Q){
    Q.base = new OtherInfo[MAXNUM];
    Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, OtherInfo e){
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXNUM;
}

bool QueueEmpty(sqQueue Q){
    return Q.front == Q.rear;
}

int LocateVex(ALGraph G, VerTexType v){
    for (int i=0;i<G.vexnum;++i){
        if (G.vertices[i].data == v){
            return i;
        }
    }
    return -1;
}

int CreateUDN(ALGraph &G){
    cout << "请输入总顶点数与总边数:\n";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入点名称:\n";
    for (int i=0;i<G.vexnum;++i){
        cout << "请输入第" << i+1 << "个点的名称:";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    cout << "请输入边的信息:\n";
    for (int i=0;i<G.arcnum;++i){
        char u,v;
        cout << "请输入第" << i+1 << "条边依附顶点名称:";
        cin >> u >> v;
        int x=LocateVex(G,u), y=LocateVex(G,v);
        ArcNode *pu = new ArcNode;
        pu->adjvex=y;
        pu->nextarc=G.vertices[x].firstarc, G.vertices[x].firstarc=pu;
        ArcNode *pv = new ArcNode;
        pv->adjvex=x;
        pv->nextarc=G.vertices[y].firstarc, G.vertices[y].firstarc=pv;
    }
    return 1;
}

void OutputG(ALGraph G){
    cout << "输出邻接表:\n";
    for (int i=0;i<G.vexnum;++i){
        cout << G.vertices[i].data << " ";
        ArcNode *p = G.vertices[i].firstarc;
        while (p){
            cout << p->adjvex << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void BFS(ALGraph G, int v, int visited[]){
    sqQueue Q;
    InitQueue(Q);
    cout << G.vertices[v].data << " ";
    visited[v] = 1;
    EnQueue(Q, v);
    while (!QueueEmpty(Q)){
        int u = Q.base[Q.front];
        Q.front = (Q.front+1)%MAXNUM;
        ArcNode *p = G.vertices[u].firstarc;
        while (p){
            if (!visited[p->adjvex]){
                cout << G.vertices[p->adjvex].data << " ";
                visited[p->adjvex] = 1;
                EnQueue(Q, p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    ALGraph myG;
    CreateUDN(myG);
    //OutputG(myG);
    cout << "请输入广度优先遍历的起点:" ;
    char u;
    cin >> u;
    BFS(myG,LocateVex(myG,u),new int[myG.vexnum]);
    return 0;
}