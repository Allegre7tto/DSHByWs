//练习2：采用邻接表表示法创建无向网
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

int main()
{
    ALGraph myG;
    CreateUDN(myG);
    OutputG(myG);
    return 0;
}