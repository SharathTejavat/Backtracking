#include <stdio.h>

int max_value = -1;

void knapsack(int a[],int k, int n,int capacity, int wt[], int val[]) {
    if (k == n) {
        int total_weight = 0;
        int total_value = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                total_weight += wt[i];
                total_value += val[i];
            }
        }
        
        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
        }
        
        return;
    }
    
    for (int i = 0; i < 2; i++) {
        a[k] = i;
        knapsack(a,k + 1, n, capacity, wt, val);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int wt[n], val[n];
    printf("Enter weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    
    printf("Enter values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    
    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    
    int a[n];
    knapsack(a,1,n,capacity, wt, val);
    
    printf("Maximum value in the knapsack: %d\n", max_value);
    return 0;
}
