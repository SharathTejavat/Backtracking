#include <stdio.h>
#include <stdbool.h>

int T, n;
int w[100];
int x[100];

void printSubset() { 
printf("the susets are");
 printf("{");
    for (int i = 1; i <= n; i++) {
      
        if (x[i]==1){
         printf("%d ",w[i]);
         }
   
}
 printf("}");
}

bool sumofsubset(int p, int k, int r) {
    if (p + w[k] == T) {
        x[k] = 1;
        printSubset();
        return true;
    } else if (p + w[k] + w[k + 1] <= T) {
        x[k] = 1;
        if (sumofsubset(p + w[k], k + 1, r - w[k]))
            return true;
    }

    if (p + r - w[k] >= T && p + w[k + 1] <= n) {
        x[k] = 0;
        if (sumofsubset(p, k + 1, r - w[k]))
            return true;
    }

    return false;
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &T);

    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        totalSum += w[i];
    }

    if (totalSum < T) {
        printf("No solution exists.\n");
    } else {
        printf("Subsets with target_sum %d is found :\n", T);
        sumofsubset(0, 1, totalSum);
    }

    return 0;
}
