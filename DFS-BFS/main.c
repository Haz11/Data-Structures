#include <stdio.h>

#define MAX 100

void bfs(int g[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int q[MAX], front = 0, rear = -1;

    visited[start] = 1;
    q[++rear] = start;

    printf("BFS: ");
    while (front <= rear) {
        int u = q[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                q[++rear] = v;
            }
        }
    }
    printf("\n");
}

void dfs(int g[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int st[MAX], top = -1;

    st[++top] = start;

    printf("DFS: ");
    while (top >= 0) {
        int u = st[top--];

        if (visited[u] == 1) continue;
        visited[u] = 1;
        printf("%d ", u);

        // عشان يكون الترتيب طبيعي: ندخل الجيران بالعكس
        for (int v = n - 1; v >= 0; v--) {
            if (g[u][v] == 1 && visited[v] == 0) {
                st[++top] = v;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int g[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter start node (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(g, n, start);
    dfs(g, n, start);

    return 0;
}
