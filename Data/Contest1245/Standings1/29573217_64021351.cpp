#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

int a[30];
int b[30];
long long f[30][2][2];
int T,i,j,k,l,L,R,s1,s2,J,K,S1,S2;

long long work(long long A,long long B)
{
	long long ans=0;
	
	if (A<0 || B<0) return 0;
	
	fo(i,0,29)
	{
		a[i]=A&1;A>>=1;
		b[i]=B&1;B>>=1;
	}
	
	memset(f,0,sizeof(f));
	f[29][0][0]=1;
	
	fd(i,29,0)
	{
		fo(j,0,1)
		{
			fo(k,0,1)
			if (f[i][j][k])
			{
				if (!j) S1=a[i]; else S1=1;
				if (!k) S2=b[i]; else S2=1;
				
				fo(s1,0,S1)
				{
					fo(s2,0,S2)
					if (!s1 || !s2)
					{
						if (s1<a[i]) J=1; else J=j;
						if (s2<b[i]) K=1; else K=k;
						
						if (!i)
						ans+=f[i][j][k];
						else
						f[i-1][J][K]+=f[i][j][k];
					}
				}
			}
		}
	}
	
	return ans;
}

int main()
{
//	freopen("f.in","r",stdin);
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d%d",&L,&R);
		printf("%I64d\n",work(R,R)-work(L-1,R)*2+work(L-1,L-1));
	}
}