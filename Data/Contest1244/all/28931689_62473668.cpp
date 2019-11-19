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
	ll n,p,w,d;cin>>n>>p>>w>>d;
	if(n*w<p){cout<<-1;return 0;}
	rep(i,0,w-1){
		ll x=p-d*i;
		if(x<0) break;
		if(x%w==0){
			ll y=x/w;
			if(y+i>n){cout<<-1;return 0;}
			cout<<y<<' '<<i<<' '<<n-y-i<<endl;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
