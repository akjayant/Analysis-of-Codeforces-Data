#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define max(a,b) (a>b?a:b)
using namespace std;

bool a[1001];
int T,n,i,j,k,l,ans;
char ch;

int main()
{
//	freopen("b.in","r",stdin);
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d",&n);ans=n;
		fo(i,1,n)
		{
			ch=getchar();
			while (ch!='0' && ch!='1')
			ch=getchar();
			
			if (ch=='0')
			a[i]=0; else a[i]=1;
		}
		
		fo(i,1,n)
		if (a[i])
		ans=max(ans,max(i,n-i+1)*2);
		
		printf("%d\n",ans);
	}
}