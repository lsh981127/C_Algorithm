#include <stdio.h>
#include <stdlib.h>
#define vertexs 8

int graph[vertexs][vertexs] = {
   {0,0,0,0,0,0,0,0},
   {0,0,6,2,16,0,0,14},
   {0,0,0,0,5,4,0,0},
   {0,0,7,0,0,3,8,0},
   {0,0,0,0,0,0,0,3},
   {0,0,0,0,4,0,0,10},
   {0,0,0,0,0,0,0,1},
   {0,0,0,0,0,0,0,0}
};

typedef struct dist_source {
    int dist;
    int prev;
}dist_source;
dist_source V[vertexs];
int visited[vertexs];
int total_cost;

int findShortest()
{
    int shortest = 10000, next;
    for (int i = 1; i < vertexs; i++)
        if ((visited[i] == 0) && (V[i].dist != 0) && (shortest > V[i].dist))
        {
            shortest = V[i].dist;
            next = i;
        }
    return next;
}

void dijkstra(int src, int dst)
{
    visited[src] = 1;
    for (int i = 1; i < vertexs; i++)
    {
        if (graph[src][i] != 0)
        {
            total_cost = graph[src][i] + V[src].dist;
            if (V[i].dist == 0 || V[i].dist > total_cost)
            {
                V[i].dist = total_cost;
                V[i].prev = src;
            }
        }
    }
    visited[src = findShortest()] = 1;
    if (src == dst)
        return;
    dijkstra(src, dst);
};

void print_path()
{
    printf("path(¿ª¼ø) : ");
    int i = 7;
    while (1)
    {
        printf("%d ", i);
        if (i == 1)
            break;
        i = V[i].prev;
    }
    puts("");
}

int main()
{
    printf("Dijkstra \n");
    printf("Start at 1 end at 7\n\n");
    dijkstra(1, 7);
    print_path();
    printf("total cost = %d\n", total_cost);
    return 0;
}