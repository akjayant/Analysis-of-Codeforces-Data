#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
using namespace std;
const int N=1e5+5,p=1e9+7;
int f[N],g[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri n,m;cin>>n>>m;
	f[1]=2;f[2]=4;
	rep(i,3,m) f[i]=(f[i-1]+f[i-2])%p;
	g[1]=2;g[2]=2;
	rep(i,3,n-1) g[i]=(g[i-1]+g[i-2])%p;
	ri s=0;
	rep(i,1,n-1) s=(s+g[i])%p;
	cout<<(f[m]+s)%p;
	return 0;
}
