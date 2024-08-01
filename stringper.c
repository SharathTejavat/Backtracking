#include<stdio.h>
int issafe(int k,int i,int a[],int n,int adj[][n])
{int l;
 if(k<(n-1))
 { 
   for(l=0;l<k;l++)
   { 
     if(a[l]==i||adj[a[k-1]][i]==0)
      return 0;
    }
    return 1;
  }
 else
 { 
   for(l=0;l<k;l++)
   { 
     if(a[l]==i||adj[a[k-1]][i]==0||adj[i][0]==0)
      return 0;
    }
    return 1;
  }
}
  
 
void hamilton(int k,int n,int a[],int adj[][n])
{ int i;
  if(k==n)
    { 
      printf("\n");
      int m;
      for(m=0;m<n;m++)
       printf("%d",a[m]);
       return;
     }
 
  for(i=1;i<n;i++)
  { 
    if(issafe(k,i,a,n,adj))
    { 
      a[k]=i;
      hamilton(k+1,n,a,adj);
     }
  }
}
    
int main()
{ 
  int n,i,j;
  printf("enter n");
  scanf("%d",&n);
  int adj[n][n];
  for(i=0;i<n;i++)
  { 
    printf("enter for %d",i);
    for(j=0;j<n;j++)
    {
     scanf("%d",&adj[i][j]);
     }
  }
  int a[n];
  a[0]=0;
  hamilton(1,n,a,adj);
 }
  
