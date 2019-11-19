#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define min(a,b) (a<b?a:b)
using namespace std;

int a[100001];
int b[100001][2];
int N,n,i,j,k,l,r,la,ra,L,R;
long long m;

int main()
{
//	freopen("e.in","r",stdin);
	
	scanf("%d%I64d",&n,&m);
	fo(i,1,n)
	scanf("%d",&a[i]);
	
	fo(i,1,n)
	if (a[i]!=a[1])
	break;
	
	if (i>n)
	{
		printf("0\n");
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	fo(i,1,n)
	if (i==1 || a[i]!=a[i-1])
	{
		++N;
		b[N][0]=a[i];
		b[N][1]=1;
	}
	else
	++b[N][1];
	
	l=1;
	r=N;
	L=b[1][1];
	R=b[N][1];
	
	while (l<r)
	{
		if (min(L,R)>m)
		break;
		
		if (L<R)
		{
			if (m>(long long)L*(b[l+1][0]-b[l][0]))
			m-=(long long)L*(b[l+1][0]-b[l][0]);
			else
			{
				printf("%d\n",b[r][0]-(b[l][0]+m/L));
				return 0;
			}
			
			++l;
			L+=b[l][1];
		}
		else
		{
			if (m>(long long)R*(b[r][0]-b[r-1][0]))
			m-=(long long)R*(b[r][0]-b[r-1][0]);
			else
			{
				printf("%d\n",(b[r][0]-m/R)-b[l][0]);
				return 0;
			}
			
			--r;
			R+=b[r][1];
		}
	}
	
	printf("%d\n",b[r][0]-b[l][0]);
}