#include<stdio.h>
#define inf 99

void  initialize(int* ptr,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  *(ptr+i*n+j)=0;
	}
    }
}

void print(int *ptr,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  printf("%d \t",*(ptr+i*n+j));
	}
      printf("\n");
    }  
}

int mini(int* ptr_ar,int* ptr_ord,int n,int i)
{
  int m,j,k,m_val,t,i_temp,j_temp;
  m_val=inf;
  i_temp=-1;
  j_temp=-1;
  for(j=0;j<i;j++)
    {
      for(k=0;k<n;k++)
	{
	  t=*(ptr_ar+(*(ptr_ord+j)*n)+k);
	  if(t<m_val && t>0)
	    {
	      m_val=t;
	      i_temp=*(ptr_ord+j);
	      j_temp=k;
	    }
	}
    }
  printf("%d \t %d ",i_temp+1,j_temp+1);
  printf("\n");
  /**(ptr_ar+n*i_temp+j_temp)=-1;
   *(ptr_ar+n*j_temp+i_temp)=-1;*/
  for(k=0;k<i;k++)
    {
      *(ptr_ar+(*(ptr_ord+k)*n)+j_temp)=-1;
      //*(ptr_ar+(*(ptr_ord+j_temp)*n)+k)=-1;
      *(ptr_ar+(j_temp*n)+*(ptr_ord+k))=-1;
    }
  m=j_temp;
  return(m);
}

int main()
{
  int i,j,n;
  printf("enter the number of vertex: ");
  scanf("%d",&n);
  int ar[n][n];
  printf("enter the weight values min-1 max-%d infinity/no-connection-%d \n",inf-1,inf);
  initialize(&(ar[0][0]),n);
  /*print(&(ar[0][0]),n);
  printf("%p \n",&ar[0]);
  printf("%p \n",&ar[0][0]);*/
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  printf("enter value of weight between %d and %d:",i+1,j+1);
	  scanf("%d",&ar[i][j]);
	  ar[j][i]=ar[i][j];
	}
    }
  printf("entered matrix \n");
  print(&(ar[0][0]),n);
  printf("enter initial vertex(1-%d):",n);
  int ver,min_val;
  scanf("%d",&ver);
  int  min[n][n];
  initialize(&(min[0][0]),n);
  int ord[n];
  ord[0]=ver-1;
  int weights[n][n];
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  weights[i][j]=ar[i][j];
	}
    } 
  for(i=1;i<n;i++)
    {
      min_val=mini(&(ar[0][0]),&ord[0],n,i);
      ord[i]=min_val;
    }
  /*printf("array \n");
    print(&ar[0][0],n);*/
  printf("order \n");
  for(i=0;i<n;i++)
    {
      printf("%d\t",ord[i]+1);
    }
  printf("\n");
  return(0);
}
