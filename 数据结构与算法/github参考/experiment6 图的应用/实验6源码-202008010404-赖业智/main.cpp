#include "grmat.h"
#include "Graph_test.h"
#include <bits/stdc++.h>
using namespace std;
Graph *createGraph(int vert_num);
Graph *G;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	G = createGraph(n);
	int fr_vert, to_vert;
	double wt;
    for(int i=0;i<m;i++)
    {   
        cin>>fr_vert>>to_vert>>wt;
        G->setEdge(fr_vert-1, to_vert-1, 1-0.01*wt);
        G->setEdge(to_vert-1, fr_vert-1, 1-0.01*wt);
    }
    option *it = new option(G);
    for (int v = 0; v < G->n(); v++)
        G->setMark(v, UNVISITED);
    double D[G->n()];
    // Dijkstra求最长路(反向才是最短路)(从0点出发至其他各点)
        for (int i = 0; i < G->n(); i++) // Initialize
            D[i] = -1;
        int a,b;
        cin>>a>>b;
        D[a-1]=0;//起点，由于从0开始，故减一 
        it->Dijkstra1(D, a-1);
        double ans=100.0/D[b-1];
		double result=ans-0.000000005;
        cout<<fixed<<setprecision(8)<<result;  
	return 0;
}

    
Graph *createGraph(int vert_num)
{
    Graph *g;
    g = new Graphm(vert_num);
    return g;
}
