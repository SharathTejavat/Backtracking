#include<stdio.h>
#include<limits.h>

int issafe(int k, int i, int a[], int n, int adj[][n]) {
    int j;
    for (j = 0; j < k; j++) {
        if (a[j] == i || adj[a[j]][i] == 0)
            return 0;
    }
    return 1;
}

int hamilton(int k, int n, int a[], int adj[][n], int wt[][n], int t[]) {
    int i, s;
    if (k == n) {
        s = 0;
        for (i = 1; i < n; i++) {
            s += wt[a[i - 1]][a[i]];
        }
        s += wt[a[n - 1]][a[0]];
        return s;
    }

    int min_cost = INT_MAX;
    for (i = 1; i < n; i++) {
        if (issafe(k, i, a, n, adj)) {
            a[k] = i;
            int cost = hamilton(k + 1, n, a, adj, wt, t);
            if (cost < min_cost)
                min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    int n, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int wt[n][n];
    printf("Enter the costs of edges:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &wt[i][j]);
        }
    }

    int t[n];
    int a[n];
    a[0] = 0;
    int min_cost = hamilton(1, n, a, adj, wt, t);
    printf("\nMin cost is %d\n", min_cost);
    printf("Hamiltonian path: ");
    for (i = 0; i < n; i++)
        printf("%d ", t[i]);

    return 0;
}

