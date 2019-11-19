#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define min(a,b) (a<b?a:b)
using namespace std;

int h[11][11];
double f[11][11];
int n,i,j,k,l,x,y,tot;
double sum;

void work()
{
	sum=0;
	tot=0;
	
	x=i;
	y=j;
	fo(k,1,6)
	{
		if ((x&1 && y==1) || (!(x&1) && y==n))
		--x;
		else
		{
			if (x&1)
			--y;
			else
			++y;
		}
		
		if (!x)
		break;
		
		++tot;
		sum+=min(f[x-h[x][y]][y],f[x][y]);
	}
	
	f[i][j]=(sum+6)/tot;
}

int main()
{
//	freopen("e.in","r",stdin);
	
	n=10;
	fo(i,1,n)
	{
		fo(j,1,n)
		scanf("%d",&h[i][j]);
	}
	
	fo(i,1,n)
	{
		if ((i&1))
		{
			fo(j,1,n)
			if (i>1 || j>1)
			work();
		}
		else
		{
			fd(j,n,1)
			work();
		}
	}
	
	printf("%0.10lf\n",f[n][1]);
}