#include <stdio.h>

void permute(int a[], int k, int n) {
    if (k == n + 1) {
        
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        
        a[k] = 0; 
        permute(a, k + 1, n); 

        a[k] = 1; 
        permute(a, k + 1, n); 
    }
}

int main() {
    int n = 3; 
    int a[n + 1]; 

    printf("All binary permutations:\n");
    permute(a, 1, n);

    return 0;
}
