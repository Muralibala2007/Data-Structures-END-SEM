#include <stdio.h>

int graph[10][10], visited[10], n;

void DFS(int start)
{
    int stack[10], top = -1, i, v;

    stack[++top] = start;
    while(top!=-1)
    {
        v = stack[top--];
        if(visited[v]==0)
        {
            printf("%d ",v);
            visited[v] = 1;
        }

        for(i=n-1;i>=0; i--)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
                stack[++top] = i;
        }
    }
}

void BFS(int start)
{
    int queue[10], front = 0, rear = 0, i, v;

    for(i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front<rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i=0;i<n;i++)
        {
            if(graph[v][i]==1&&visited[i]==0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;
    printf("Enter Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter Starting Vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for(int i=0;i<n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);
}