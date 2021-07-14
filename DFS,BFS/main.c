#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int matrix_graph[MAX][MAX];
int visit[MAX];
int xsize, ysize;
void ReadFile()
{
    int i = -1, temp = 0;
    char fdata;
    FILE* fp;
    fp = fopen("matrix_graph.txt", "r");
    while (1)
    {
        int j = 0;
        while (1)
        {
            fdata = fgetc(fp);
            if (fdata == '\n' || fdata == EOF)
                break;
            else if(fdata ==' ');
            else if(i != -1){
            matrix_graph[temp][i] = (int)(fdata - '0');
            j++;
            temp = j;
            }
        }
        i++;
        if (fdata == EOF)
            break;
    }
    xsize = temp;
    ysize = i-1;

    fclose(fp);
}


void DFS(int v, int n)
{
    int i;
    visit[v]= 1;
    printf("%d ",v);

    for(i=0; i<=n; i++){
        if(matrix_graph[v][i] == 1 && visit[i] == 0 ){
            DFS(i, n);
        }
    }
    return;
}
int main()
{

    ReadFile();
    DFS(4,xsize);
    printf("\n");



    return 0;
}
