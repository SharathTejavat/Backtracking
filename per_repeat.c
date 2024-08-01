#include<stdio.h>

void per(int j,int p[],int n)
{ int i;
  if(j==n)
  { int l;
    for(l=0;l<n;l++)
    { 
     printf("%d",p[l]);
    }
    printf("\n");
    return;
  }

  for(i=0;i<2;i++)
  { 
    
        p[j]=i;
        per(j+1,p,n);
       
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
