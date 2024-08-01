#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int is_safe(int a[],int k,int current){
for (int i=1;i<k;i++){
if(a[i]==current){
return 0;
}
}
return 1;
}

int c=0;
int per(int a[],int k,int n){
 if (k==n+1){
 for (int i=1;i<=n;i++){
 c++;
 printf("%d ",a[i]);
 }
 printf("\n");
 }
 else{
  for (int i=1;i<=n;i++){
   if(is_safe(a,k,i)){
     a[k]=i;
     per(a,k+1,n);
     }
     }
}
}

int main(){
int n=4;
int a[n+1];
per(a,1,n);
printf("no.of permutations are :%d",c);
return 0;
}
 
