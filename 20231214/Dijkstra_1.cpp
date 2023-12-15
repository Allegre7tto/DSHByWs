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
            G.arcs[i][j] = MAXINT;
        }
    }
    cout << "请输入边的信息:\n";
    for (int i=0;i<G.arcnum;++i){
        char u,v;
        int w;
        cout << "请输入第" << i+1 << "条边依附顶点名称及其权值:";
        cin >> u >> v >> w;
        int x=LocateVex(G,u);
        int y=LocateVex(G,v);
        G.arcs[x][y] = w;
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

void Dijkstra(AMGraph G, int v0,int* Distance,int* prior){
    int vis[MAXNUM];
    for (int i=0;i<G.vexnum;++i){
        vis[i] = 0;
        Distance[i] = G.arcs[v0][i];
        prior[i] = 0;
    }
    Distance[v0] = 0;
    vis[v0] = 1;
    for (int i=1;i<G.vexnum;++i){
        int minD = MAXINT;
        int k = 0;
        for (int j=0;j<G.vexnum;++j){
            if (vis[j] == 0 && Distance[j] < minD){
                minD = Distance[j];
                k = j;
            }
        }
        vis[k] = 1;
        for (int j=0;j<G.vexnum;++j){
            if (vis[j] == 0 && (minD + G.arcs[k][j] < Distance[j])){
                Distance[j] = minD + G.arcs[k][j];
                prior[j] = k;
            }
        }
    }
}

int main()
{
    AMGraph G;
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
        tmp = G.vexs[prior[LocateVex(G,tmp)]];
    } cout << start <<endl;
    return 0;
}