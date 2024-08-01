#include<stdio.h>
#include<string.h>
int issafe(int j,int i,int p[])
{ int k;
 for(k=0;k<j;k++)
  {  
    if(p[k]==i)
    return 0;
  }
  return 1;
}
void per_char(int j,int p[],int n,char a[])
{ int i;
  if(j==n)
  { int l;
    for(l=0;l<n;l++)
    { int m=p[l];
     printf("%c",a[m]);
    }
    printf("\n");
    return;
  }

  for(i=0;i<n;i++)
  { 
    if(issafe(j,i,p))
      { 
        p[j]=i;
        per_char(j+1,p,n,a);
       }
   }
 }
int main()
{ 
  int n;
  int i;
  char ch;
  printf("enter n");
  scanf("%d",&n);
  char a[3];
char s[3]="abc";
for(i=0;i<n;i++)
a[i]=s[i];
//for(i=0;i<n;i++)
//printf("%c",a[i]);
  int p[n];
 per_char(0,p,n,a);
}
