#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

namespace Solve1
{
	const int maxn=100005;
	int n,L[maxn]; 
	void work()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&L[i]);
		sort(L+1,L+n+1);
		int xx=(n+1)>>1;
		long long tx=0,ty=0;
		for(int i=n;i>=n-xx+1;i--) tx+=L[i];
		for(int i=n-xx;i>=1;i--) ty+=L[i];
		cout<<tx*tx+ty*ty<<endl;
		return;
	}
}
int main()
{
	#ifdef LOCAL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	Solve1::work();
	
	return 0;
}
