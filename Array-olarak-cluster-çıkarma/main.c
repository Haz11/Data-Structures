#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int g[MAX][MAX];
    int visited[MAX] = {0};
    int stack[MAX];
    int top;
    int clusters = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    // find clusters
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            clusters++;
            printf("\nCluster %d: ", clusters);

            // DFS using stack
            top = -1;
            stack[++top] = i;
            visited[i] = 1;

            while (top >= 0) {
                int u = stack[top--];
                printf("%d ", u);

                for (int v = 0; v < n; v++) {
                    if (g[u][v] == 1 && visited[v] == 0) {
                        visited[v] = 1;
                        stack[++top] = v;
                    }
                }
            }
            printf("\n");
        }
    }

    printf("\nTotal clusters = %d\n", clusters);
    return 0;
}
