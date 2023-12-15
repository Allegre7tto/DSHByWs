#include <iostream>
using namespace std;

const long long MAXINT = 32767;
const long long MAXNUM = 100;

typedef char VerTexType;
typedef int ArcType;

typedef struct {
    VerTexType vexs[MAXNUM];
    ArcType arcs[MAXNUM][MAXNUM];
    int vexnum, arcnum;
} AMGraph;

typedef struct {
    ArcType *base;
    int front, rear;
} sqQueue;

void InitQueue(sqQueue &Q){
    Q.base = new ArcType[MAXNUM];
    Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, ArcType e){
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXNUM;
}

bool QueueEmpty(sqQueue Q){
    return Q.front == Q.rear;
}

int LocateVex(AMGraph G, VerTexType v){
    for (int i=0;i<G.vexnum;++i){
        if (G.vexs[i] == v){
            return i;
        }
    }
    return -1;
}

int CreateUDN(AMGraph &G){
    cout << "请输入总顶点数与总边数:\n";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入点名称:\n";
    for (int i=0;i<G.vexnum;++i){
        cout << "请输入第" << i+1 << "个点的名称:";
        cin >> G.vexs[i];
    }
    for (int i=0;i<G.vexnum;++i){
        for (int j=0;j<G.vexnum;++j){
            G.arcs[i][j] = 0;
        }
    }
    cout << "请输入边的信息:\n";
    for (int i=0;i<G.arcnum;++i){
        char u,v;
        int w=1;
        cout << "请输入第" << i+1 << "条边依附顶点名称:";
        cin >> u >> v ;
        int x=LocateVex(G,u);
        int y=LocateVex(G,v);
        G.arcs[x][y] = G.arcs[y][x] = w;
    }
    return 0;
}

void OutputG(AMGraph G){
    cout << "输出邻接矩阵:\n";
    for (int i=0;i<G.vexnum;++i){
        for (int j=0;j<G.vexnum;++j){
            cout << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(AMGraph G, int v, int visited[]){
    sqQueue Q;
    InitQueue(Q);
    cout << G.vexs[v] << " ";
    visited[v] = 1;
    EnQueue(Q,v);
    while (!QueueEmpty(Q)){
        int u = Q.base[Q.front];
        Q.front = (Q.front+1)%MAXNUM;
        for (int w=0;w<G.vexnum;++w){
            if (G.arcs[u][w] && !visited[w]){
                cout << G.vexs[w] << " ";
                visited[w] = 1;
                EnQueue(Q,w);
            }
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);
    //OutputG(G);
    cout << "请输入广度优先遍历的起点:" ;
    char u;
    cin >> u;
    BFS(G,LocateVex(G,u),new int[G.vexnum]);
    return 0;
}