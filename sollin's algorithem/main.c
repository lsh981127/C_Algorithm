#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERTICES 9

typedef struct Edge
{
    int src, dest, weight;
}Edge;
struct Graph
{
    int V, E;
    Edge *edge;
};

int graph[VERTICES][VERTICES];
int G[VERTICES][VERTICES] = {  {0,0,0,0,0,0,0,0,0},
                                    {0,0,2,8,0,0,0,0,0},
                                    {0,2,0,7,9,0,0,0,0},
                                    {0,8,7,0,4,10,12,0,0},
                                    {0,0,9,4,0,0,0,0,0},
                                    {0,0,0,10,0,0,6,14,0},
                                    {0,0,0,12,0,6,0,0},
                                    {0,0,0,0,0,14,0,0,3},
                                    {0,0,0,0,0,0,0,3,0}   };

typedef struct subset
{
    int parent;
    int rank;
}subset;

int find(struct subset subsets[], int i);

void Union(struct subset subsets[], int x, int y);

Edge* make_edges(int graph[VERTICES][VERTICES], int V, int E);

void boruvkaMST(int graph[VERTICES][VERTICES], int V, int E)
{

  Edge* edge = make_edges(G, V, E);
  struct subset *subsets =  malloc(sizeof(subset[V]));
  int *cheapest = malloc(sizeof(int[V]));

  for (int v = 0; v < V; ++v)
  {
    subsets[v].parent = v;
    subsets[v].rank = 0;
    cheapest[v] = -1;
  }

  int numTrees = V;
  int MSTweight = 0;


  while (numTrees > 1)
  {

    for (int i=0; i<E; i++)
    {

      int set1 = find(subsets, edge[i].src);
      int set2 = find(subsets, edge[i].dest);


      if (set1 == set2)
        continue;
      else
      {
      if (cheapest[set1] == -1 ||
        edge[cheapest[set1]].weight > edge[i].weight)
        cheapest[set1] = i;

      if (cheapest[set1] == -1 ||
        edge[cheapest[set2]].weight > edge[i].weight)
        cheapest[set2] = i;
      }
    }


    for (int i=0; i<V; i++)
    {

      if (cheapest[i] != -1)
      {
        int set1 = find(subsets, edge[cheapest[i]].src);
        int set2 = find(subsets, edge[cheapest[i]].dest);

        if (set1 == set2)
          continue;
        MSTweight += edge[cheapest[i]].weight;
        printf("Edge %d-%d included in MST\n",
          edge[cheapest[i]].src, edge[cheapest[i]].dest,
          edge[cheapest[i]].weight);



        Union(subsets, set1, set2);
        numTrees--;
      }
    }
  }

  printf("%d \n", MSTweight);
  return;
}


int find(struct subset subsets[], int i)
{

        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);

        return subsets[i].parent;
}


void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);


    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

Edge* make_edges(int graph[VERTICES][VERTICES], int V, int E)
{
    Edge *edge;
    edge = malloc(sizeof(Edge[E]));
    int c = 0;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(graph[i][j]>0 && graph[i][j]<999){
                edge[c].src = i;
                edge[c].dest = j;
                edge[c].weight = graph[i][j];
                c++;
            }
        }
    }
    return edge;
}

void take_input()
{

    for(int i=0;i<VERTICES;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(G[i][j] != 0)
            {
                graph[i][j] = G[i][j];
    }
}

int main()
{
  int V, E;
  take_input(V);
  boruvkaMST(graph, V, E);
  return 0;
}

