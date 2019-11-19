#include<bits/stdc++.h>
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef priority_queue<int> BQ;
typedef priority_queue<int,vector<int>,greater<int> > SQ;
const int maxn=1e5+10,mod=1e9+7,INF=0x3f3f3f3f;
inline ll add(ll a,ll b){
	a+=b;
	return a>=mod?a-mod:a;
}
ll f[maxn];
int main()
{
	ll n,m;
	cin>>n>>m;
	f[1]=1;
	f[2]=2;
	for (int i=3;i<=max(n,m);++i)
		f[i]=add(f[i-1],f[i-2]);
	ll ans=((f[m]*2%mod-2+mod)%mod+2*f[n]%mod)%mod;;
	cout<<ans;
	return 0;
}
