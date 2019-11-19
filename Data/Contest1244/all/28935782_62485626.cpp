/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 100016, MOD = 1000000007;

int cost[4][M];
vector<int> edg[M];
int color[M], tmpcolor[M];
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int n = read();
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=n; ++j)
			cost[i][j] = read();
	for(int i=1; i<n; ++i)
	{
		int a = read(), b = read();
		edg[a].push_back(b);
		edg[b].push_back(a);
	}
	int st=-1;
	for(int i=1; i<=n; ++i)
	{
		if(edg[i].size()>2) 
		{
			printf("-1\n");
			return 0;
		}
		if(edg[i].size()==1)
		{
			st = i;
		}
	}
	int st2 = edg[st].back();
	ll ans = LLONG_MAX;
	for(int c1=1; c1<=3; ++c1) for(int c2=1; c2<=3; ++c2) if(c1!=c2)
	{
		ll tmp = 0ll+cost[c1][st]+cost[c2][st2];
		tmpcolor[st] = c1, tmpcolor[st2] = c2;

		int lstc = c1, nowc = c2;
		for(int lst=st, now=st2; edg[now].size()==2; )
		{
			int nxt = edg[now][0]^edg[now][1]^lst;
			lst = now;
			now = nxt;

			int nxtc = lstc^nowc;
			lstc = nowc;
			nowc = nxtc;
		//	printf("%d %d\n",now,nowc );
			tmpcolor[now] = nowc;
			tmp += cost[nowc][now];
		}
		//printf("%I64d %I64d\n",tmp,ans );
		if(tmp<ans)
		{
			for(int i=1; i<=n; ++i)
				color[i] = tmpcolor[i];
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	for(int i=1; i<=n; ++i)
		printf("%d ",color[i] );
    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}