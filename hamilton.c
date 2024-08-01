#include<stdio.h>
int issafe(int a[],int index,int val,int n,int adj[][n])
{
 if(index==n-1)
 { 
   for(int i=0;i<index;i++)
   { 
     if(a[i]==val||adj[a[index-1]][val]==0)
      return 0;
    }
    return 1;
  }
 else
 { 
   for(int i=0;i<index;i++)
   { 
     if(a[i]==val||adj[a[index-1]][val]==0||adj[val][0]==0)
      return 0;
    }
    return 1;
  }
}
  
 int c=0;
void hamilton(int a[],int k,int n,int adj[][n])
{ int i;
  if(k==n)
    { 
     // int c=0;
      for(i=0;i<n;i++){
      c++;
       printf("%d",a[i]);
       }
       printf("%d\n",a[0]);
       return;
     }
 
  for(i=1;i<n;i++)
  { 
    if(issafe(a,k,i,n,adj))
    { 
      a[k]=i;
      hamilton(a,k+1,n,adj);
     }
  }
}
    
int main()
{ 
  int n,i,j;
  printf("enter size of the cycle : ");
  
  scanf("%d",&n);
  int adj[n][n];
  printf("enter the adjacency matrix:\n");
  for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
     scanf("%d",&adj[i][j]);
     }
  }
  int a[n];
  a[0]=0;
  hamilton(a,1,n,adj);
  printf("The no.of cycles are :%d",c);
 }
  
