#include "grlist.h"
#include "grmat.h"
#include "Graph_test.h"
Graph *createGraph(int graph_type, int vert_num);

int main()
{
    Graph* G;
    int vert_num;                     // 图的顶点数，编号从0开始
    cin >> vert_num;

    int graph_type = 1;               // graph_type=1, 采用临接链表表示图   graph_type=0, 采用临接矩阵表示图

    G = createGraph(graph_type, vert_num);

    option *it = new option(G);

    for (int v = 0; v < G->n(); v++)
        G->setMark(v, UNVISITED);  // Initialize mark bits

    int edge_num;
    cin >> edge_num;

    int fr_vert, to_vert, wt;

    while(edge_num--)
    {
        cin >> fr_vert >> to_vert >> wt;
        fr_vert --;
        to_vert --;
        G->setEdge(fr_vert, to_vert, wt);
        G->setEdge(to_vert, fr_vert, wt);
    }
    int D[G->n()];
    for (int i = 0; i < G->n(); i++) // Initialize
        D[i] = INFINITY;
    D[0] = 0;
    cout << it->Prim(D, 0) << "\n";
    return 0;
}

Graph *createGraph(int graph_type, int vert_num)
{
    Graph *g;
    if (graph_type)
        g = new Graphl(vert_num);
    else
        g = new Graphm(vert_num);

    return g;
}
