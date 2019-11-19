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

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri T;cin>>T;
	while(T--){
		ri n,m,t1=0,t2=0,t3=0,t4=0;cin>>n;
		rep(i,1,n){
			ri x;cin>>x;
			if(x&1) ++t1;
		}
		t2=n-t1;cin>>m;
		rep(i,1,m){
			ri x;cin>>x;
			if(x&1) ++t3;
		}
		t4=m-t3;
		ll ans=1ll*t1*t3+1ll*t2*t4;
		cout<<ans<<endl;
	}
	return 0;
}
