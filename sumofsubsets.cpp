#include<stdio.h>
void sos(int k,int n,int a[],int s,int wt[])
{ 
 int i;
 if(k==n)
 { 
     int sum=0;
     int l;
     for(l=0;l<n;l++)
      { 
        if(a[l]==1)
         sum=sum+wt[l];
      }
     if(sum==s)
     {
       printf("\n");
       for(l=0;l<n;l++)
       { 
         if(a[l]==1)
         printf("%d ",wt[l]);
       }
     
     }
     return;
  }
    
  for(i=0;i<2;i++)
  { 
    a[k]=i;
    sos(k+1,n,a,s,wt);
  }
}
  
int main()
{ 
  int n;
  printf("enter n");
  scanf("%d",&n);
  int wt[n];
  int i;
  printf("enter weights");
  for(i=0;i<n;i++)
  scanf("%d",&wt[i]);
  int s;
  printf("enter sum");
  scanf("%d",&s);
  int a[n];
  sos(0,n,a,s,wt);
 }
  
