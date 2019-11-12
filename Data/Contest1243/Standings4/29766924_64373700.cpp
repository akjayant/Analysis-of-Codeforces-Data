#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e9
#define eps 1e-6
#define N 1010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int a[N],n;
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for(register int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);int ans=0;
		for(register int i=n;i>=1;i--)
		{
			int len=min(n-i+1,a[i]);
			ans=max(ans,len);
		}
		printf("%d\n",ans);
	}
	return 0;
}
