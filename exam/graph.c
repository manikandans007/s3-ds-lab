#include <stdio.h>
#include <stdlib.h>
#define max 20

int e, front = -1, rear = -1, queue[max], i, k, top = -1, stack[max];

void bfs(int adj[][max], int visited[], int start) {
    for (k = 0; k < e; k++) {
        visited[k] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%c-", start + 65);

        for (i = 0; i < e; i++) {
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

void dfs(int adj[][max], int visited[], int start) {
    int top = -1, stack[max];

    for (int k = 0; k < e; k++) {
        visited[k] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top--];
        printf("%c-", start + 65);

        for (int i = 0; i < e; i++) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

int main() {
    int j, v1, ch;
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    int visited[max] = {0};
    int adj[max][max];

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < e; i++) {
        for (j = 0; j < e; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (i = 0; i < e; i++) {
        for (j = 0; j < e; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the vertex you want to perform: ");
    scanf("%d", &v1);
  do{  
    printf("\n1. BFS");
    printf("\n2. DFS");
    printf("\nEnter the option you want to perform: ");
    scanf("%d", &ch);
        switch (ch)
         {
            case 1:
                bfs(adj, visited, v1);
                break;
            case 2:
                dfs(adj, visited, v1);
                break;
            case 3:
                printf("\nEnter wrong number");
                break;
        }
       
    }while(ch<4);
}

