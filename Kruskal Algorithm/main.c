#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define swap(x, y) ((x)^=(y)^=(x)^=(y))
#define VERTICES 9

int graph[VERTICES][VERTICES] = {  {0,0,0,0,0,0,0,0,0},
                                    {0,0,2,8,0,0,0,0,0},
                                    {0,2,0,7,9,0,0,0,0},
                                    {0,8,7,0,4,10,12,0,0},
                                    {0,0,9,4,0,0,0,0,0},
                                    {0,0,0,10,0,0,6,14,0},
                                    {0,0,0,12,0,6,0,0},
                                    {0,0,0,0,0,14,0,0,3},
                                    {0,0,0,0,0,0,0,3,0}   };

typedef struct edge* eptr;
typedef struct edge {
   int src, dst, cost;
   eptr next;
}edge;
eptr E, T;
int Ecnt, Tcnt, edgecnt;
int Union[VERTICES] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};


void AddE(int src, int dst, int cost)
{
   eptr newedge = malloc(sizeof(edge));
   newedge->src = src;
   newedge->dst = dst;
   newedge->cost = cost;
   newedge->next = NULL;
   if (E == NULL)
      E = newedge;
   else
   {
      eptr curr = E;
      while (curr->next != NULL)
         curr = curr->next;
      curr->next = newedge;
   }
}
void AddT(eptr a)
{
   eptr newedge = malloc(sizeof(edge));
   newedge->src = a->src;
   newedge->dst = a->dst;
   newedge->cost = a->cost;
   newedge->next = NULL;
   if (T == NULL)
      T = newedge;
   else
   {
      eptr curr = T;
      while (curr->next != NULL)
         curr = curr->next;
      curr->next = newedge;
   }
}

void sortE()
{
   for (int i = 0; i < Ecnt; i++)
   {
      eptr curr = E;
      for (int j = 0; j < Ecnt - (1 + i); j++)
      {
         if (curr != NULL)
         {
            if (curr->cost > (curr->next)->cost)
            {
               swap(curr->src, curr->next->src);
               swap(curr->dst, curr->next->dst);
               swap(curr->cost, curr->next->cost);
            }
            curr = curr->next;
         }
      }
   }
}
void initE()
{
   for (int i = 0; i < VERTICES; i++)
   {
      for (int j = 0; j <= i; j++)
      {
         if (graph[i][j] != 0)
         {
            Ecnt++;
            AddE(j, i, graph[i][j]);
         }
      }
   }
   edgecnt = Ecnt;
   sortE();
}

void printE()
{
   eptr curr = E;
   printf("기존 그래프에 있던 간선의 갯수: %d\n", Ecnt);
   if (curr != NULL)
   {
      for (int i = 0; i < Ecnt; i++)
      {
         printf("%d -> %d, cost : %d\n", curr->src, curr->dst, curr->cost);
         curr = curr->next;
      }
   }
   puts("");
}
void printT()
{
   eptr curr = T;
   printf("Kruskal 알고리즘을 적용한 간선의 갯수) : %d\n", Tcnt);
   if (curr != NULL)
   {
      for (int i = 0; i < Tcnt; i++)
      {
         printf("%d -> %d, cost : %d\n", curr->src, curr->dst, curr->cost);
         curr = curr->next;
      }
   }
   puts("");
}
void print_graph()
{
   printf("원래의 graph :\n");
   for (int i = 0; i < VERTICES; i++) {
      for (int j = 0; j < VERTICES; j++)
      {
         if (graph[i][j] > 9)
            printf(" %d ", graph[i][j]);
         else
            printf(" %d  ", graph[i][j]);
      }
      puts("");
   }
   puts("");
}

int getUnion(int a)
{
   if (Union[a] == a)
      return a;
   else
      return Union[a] = getUnion(Union[a]);
}
bool Iscycle(int a, int b)
{
   a = getUnion(a);
   b = getUnion(b);
   if (a == b)         // 사이클이면 참 반환
      return true;
   else                // 사이클이 아닐 시 병합 후 거짓 반환
   {
      if (a < b)
         Union[b] = a;
      else
         Union[a] = b;
      return false;
   }
}
void kruskal()
{
   while (Ecnt != 0 && Tcnt != edgecnt)
   {
      eptr curr = E;
      E = E->next;
      Ecnt--;
      if (Iscycle(curr->src, curr->dst) == false)  // 사이클이 생기지 않으면 T에 간선 추가
      {
         AddT(curr);
         Tcnt++;
      }
      free(curr);
   }

}

void FreeNODE(eptr head)
{
   if (head != NULL) {
      eptr curr = head->next;
      while (curr != NULL)
      {
         eptr temp = curr->next;
         free(curr);
         curr = temp;
      }
      free(curr);
      free(head);
   }
}

int main()
{
   initE();
   printE();
   kruskal();
   printT();


   FreeNODE(E);
   FreeNODE(T);
    return 0;
}
