#include <stdio.h>
#include <stdlib.h>
#define VERTICES 9

#define MAX_INT 99999
#define NOTDEF  -1
#define OUTOFQ  -1

// [in][out]
int graph[VERTICES][VERTICES] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 2, 8, 0, 0, 0, 0, 0},
    { 0, 2, 0, 7, 9, 0, 0, 0, 0},
    { 0, 8, 7, 0, 4, 10, 12, 0, 0},
    { 0, 0, 9, 4, 0, 0, 0, 0, 0},
    { 0, 0, 0, 10, 0, 0, 6, 14, 0},
    { 0, 0, 0, 12, 0, 6, 0, 0},
    { 0, 0, 0, 0, 0, 14, 0, 0, 3},
    { 0, 0, 0, 0, 0, 0, 0, 3, 0}
};


int key[VERTICES];
int pred[VERTICES];
int Q[VERTICES];
int Qcount;

void PQinit()
{
    Qcount = 0;
}

int PQinsert(int a)
{
    Q[a] = 0;
    Qcount++;
}

int PQdelmin()
{
    int i;
    int min = MAX_INT;
    int saveindex = OUTOFQ;
    for (i = 0; i < VERTICES; i++) {
        if (Q[i] == OUTOFQ)
            continue;
        if (key[i] < min) {
            saveindex = i;
            min = key[i];
        }
    }
    if (saveindex == OUTOFQ) {
        Qcount--; return OUTOFQ;
    }
    Q[saveindex] = OUTOFQ;
    Qcount--;
    return saveindex;
}

int PQisempty()
{
    if (Qcount == 0) return 1;
    return 0;
}

int PQdeckey(int w, int newkey)
{
    key[w] = newkey;
}

void Prim(int start)
{
    int i, v, w;
    PQinit();
    for (i = 0; i < VERTICES; i++) {
        key[i] = MAX_INT;
        pred[i] = NOTDEF;
        PQinsert(i);
    }

    key[start] = 0;
    while (!PQisempty()) {
        v = PQdelmin();
        printf("%d %c\n", v, v + 'A');
        for (w = 0; w < VERTICES; w++) {
            if ((graph[v][w] != 0) && (key[w] > graph[v][w])) {
                PQdeckey(w, graph[v][w]);
                pred[w] = v;
            }
        }
    }
}

int main()
{
    Prim(3);
    return 0;
}
