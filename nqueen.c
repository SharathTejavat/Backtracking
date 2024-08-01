#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_safe(int a[], int k, int current) {
    for (int i = 1; i < k; i++) {
        if (a[i] == current || abs(k - i) == abs(current - a[i])) {
            return 0;
        }
    }
    return 1;
}


void print(int a[],int n){
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
 if(j==a[i]){
  printf("1 ");
  }
  else{
  printf("0 ");
  }
  }
  printf("\n");
  }
  printf("\n");
  }
int count=0;
int per(int a[], int k, int n) {
    if (k == n + 1) {
       for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        count++;
        print(a,n);
    } else {
        for (int i = 1; i <= n; i++) {
            if (is_safe(a, k, i)) {
                a[k] = i;
                per(a, k + 1, n);
            }
        }
    }
}

int main() {
 printf("Enter the no.of rows for the square Board (chessboard size) ");
 int n;
 scanf("%d",&n);
    
    int a[n + 1];
    per(a, 1, n);
    printf("Total no.of combinations for given n :%d is %d",n,count);
    return 0;
}
