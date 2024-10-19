#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include "grmat.h"
#include <queue>

using namespace std;

class option
{
private:
    Graph *G;
public:
// Start with some implementations for the abstract functions
    option(Graph *g)
    {
        G = g;
    }
    
    
    void Dijkstra1(double* D, int s)
    {
    	int i,v,w;
    	for(i=0;i<G->n();i++){
    		v=maxVertex(D);
    		if(D[v]==-1) return;
    		G->setMark(v,VISITED);	
    		for(w=G->first(v);w<G->n();w=G->next(v,w)){
    			if(D[w]>1.0) D[w]=0.0;
    			if(D[v]==0) D[v]=1.0;
				double x=1.0*D[w];
    			double y=1.0*(D[v]*G->weight(v,w)); 
    		if(x<y)
    			D[w]=y;//顺找最长路(0.98和0.99比，选0.99) 
    		}
		}
    }

    int maxVertex(double* D)   // Find min cost vertex
    {
        int i, v = -1;
        // Initialize v to some unvisited vertex
        for (i = 0; i < G->n(); i++)
            if (G->getMark(i) == UNVISITED)
            {
                v = i;
                break;
            }
        for (i++; i < G->n(); i++) // Now find smallest D value
            if ((G->getMark(i) == UNVISITED) && (D[i] > D[v]))
                v = i;
        return v;
    }

};


#endif // GRAPH_TEST_H_INCLUDED
