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
        int w;
        cout << "请输入第" << i+1 << "条边依附顶点名称及其权值:";
        cin >> u >> v >> w;
        int x=LocateVex(G,u), y=LocateVex(G,v);
        ArcNode *pu = new ArcNode;
        pu->adjvex=y;
        pu->nextarc=G.vertices[x].firstarc, G.vertices[x].firstarc=pu;
        pu->info=w;
        // ArcNode *pv = new ArcNode;
        // pv->adjvex=x;
        // pv->nextarc=G.vertices[y].firstarc, G.vertices[y].firstarc=pv;
        // pv->info=w;
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

void Dijkstra(ALGraph G, int u, int *Distance, int *prior){
    int vis[MAXNUM];
    for (int i=0;i<G.vexnum;++i){
        vis[i]=0;
        Distance[i]=MAXINT;
        prior[i]=0;
    }
    vis[u]=1;
    Distance[u]=0;
    ArcNode *tmp = G.vertices[u].firstarc;
    while (tmp){
        Distance[tmp->adjvex]=tmp->info;
        prior[tmp->adjvex]=u;
        tmp=tmp->nextarc;
    }
    delete tmp;
    for (int i=1;i<G.vexnum;++i){
        int minD=MAXINT;
        int v;
        for (int w=0;w<G.vexnum;++w){
            if (!vis[w] && Distance[w]<minD){
                v=w;
                minD=Distance[w];
            }
        }
        vis[v]=1;
        ArcNode *tmp = G.vertices[v].firstarc;
        while (tmp){
            if (!vis[tmp->adjvex] && (minD+tmp->info<Distance[tmp->adjvex])){
                Distance[tmp->adjvex]=minD+tmp->info;
                prior[tmp->adjvex]=v;
            }
            tmp=tmp->nextarc;
        }
        delete tmp;
    }
}

int main()
{
    ALGraph G;
    CreateUDN(G);
    //OutputG(G);
    int Distance[MAXNUM],prior[MAXNUM];
    char start,end;
    cout << "请输入起点和终点:";
    cin >> start >> end;
    Dijkstra(G,LocateVex(G,start),Distance,prior);
    cout << "最短路为:" << Distance[LocateVex(G,end)] << endl;
    cout << "路径为:";
    char tmp = end;
    while (tmp!=start){
        cout << tmp << "<-";
        tmp = G.vertices[prior[LocateVex(G,tmp)]].data;
    }cout << start <<endl;
    return 0;
}