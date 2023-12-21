//练习1：采用邻接矩阵表示法创建无向网
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

int main()
{
    AMGraph G;
    CreateUDN(G);
    OutputG(G);
    return 0;
}