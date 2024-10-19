#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>
#include "graph.h"
#include "grmat.h"

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


    void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))   // Depth first search
    {
        if(G->getMark(v) == VISITED) return ;
        PreVisit(v);
        Visiting(v);
        G->setMark(v, VISITED);
        for(int i = G->first(v); i != G->n(); i = G->next(v, i))
            DFS(i, PreVisit, PostVisit, Visiting);
        PostVisit(v);
    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
        std::queue<int> q;
        PreVisit(start);
        G->setMark(start, VISITED);
        q.push(start);
        while(!q.empty())
        {
            start = q.front(); q.pop();
            Visiting(start);
            for(int i = G->first(start); i != G->n(); i = G->next(start, i))
            {
                if(G->getMark(i) == VISITED) continue;
                PreVisit(i);
                G->setMark(i, VISITED);
                q.push(i);
            }
            PostVisit(start);
        }
    }

    void Dijkstra1(int* D, int s)
    {
        for(int i = 0; i < G->n(); ++i)
        {
            int k = minVertex(D);
            G->setMark(k, VISITED);
            for(int j = G->first(k); j != G->n(); j = G->next(k, j))
                if(D[j] > D[k] + G->weight(k, j))
                    D[j] = D[k] + G->weight(k, j);
        }
    }

    int minVertex(int* D)   // Find min cost vertex
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
            if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
                v = i;
        return v;
    }

    void AddEdgetoMST(int v1, int v2)
    {
        cout << "Add edge " << v1 << " to " << v2 << "\n";
    }
    int Prim(int* D, int s)   // Prim's MST algorithm
    {
        int res = 0;
        int V[G->n()];
        for(int i = 0; i < G->n(); ++i) V[i] = i;
        G->setMark(s, VISITED);
        for(int i = 1; i < G->n(); ++i)
        {
            for(int j = G->first(s); j != G->n(); j = G->next(s, j))
                if(D[j] > G->weight(s, j))
                    D[j] = G->weight(s, j), V[j] = s;
            s = minVertex(D);
            if(V[s] == s) return -1;
            G->setMark(s, VISITED);
            res += G->weight(V[s], s);
        }
        return res;
    }
};

#endif // GRAPH_TEST_H_INCLUDED
