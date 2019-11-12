#include<bits/stdc++.h>
using namespace std;
//#include<ext/rope>
//using namespace __gnu_cxx
//#include<ext/pb_ds/priority_queue.hpp>
//using namespace __gnu_pbds;
#define lowbit(x) (x&-x)
#define pb push_back
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
#define clr(a,b) memset(a,b,sizeof(a))
#define caze(T) for(cin>>T;T;T--)
#define inf (1<<29)
#define Endl ('\n')
#define fi first
#define se second
#define db double
#define ldb long double
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
inline char nc() {
	#define SZ 1000000
	static char buf[SZ], *p1, *p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline int scan(T &x) {
	char c, sign=1; 
	while(!isdigit(c=nc())&&c!=EOF)if(c=='-')sign*=-1;
	if(c==EOF) return EOF;
	for(x = 0; isdigit(c); c = nc())
		x = (x<<1) + (x<<3) + (c&15);
	return x *= sign, 1;
}
template<typename T, typename...Args>
inline int scan(T &x, Args&...args) {
	return scan(x), scan(args...);
}
int dp[111][111][111];
int main()
{
	clr(dp,0);
	for(int i=1;i<=100;++i)
		for(int j=1;j<=100;++j)
			for(int k=1;k<=100;++k)
			{
				if(i>=1&&j>=2)
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-2][k]+3);
				if(j>=1&&k>=2)
					dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-2]+3);
			}
	int T;caze(T)
	{
		int a,b,c,ans=0;
		cin>>a>>b>>c;
		for(int i=0;i<=a;++i)
			for(int j=2*i;j<=b;++j)
				ans=max(ans,3*i+3*min(j-2*i,c/2));
		cout<<ans<<endl;
	}
}