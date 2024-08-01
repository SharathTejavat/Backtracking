#include<stdio.h>
int issafe(int j,int i,int p[])
{ int k;
 for(k=0;k<j;k++)
  {  
    if(p[k]==i)
    return 0;
  }
  return 1;
}
void per(int j,int p[],int n)
{ int i;
  if(j==n)
  { int l;
    for(l=0;l<n;l++)
    { 
     printf("%d",p[l]);
    }
    printf("\n");
  }

  for(i=0;i<n;i++)
  { 
    if(issafe(j,i,p))
      { 
        p[j]=i;
        per(j+1,p,n);
       }
   }
 }
        
      
int main()
{
 int n;
printf("enter n");
scanf("%d",&n);
int p[n];
per(0,p,n);
}
