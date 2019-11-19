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
int a[1000005],b[1000005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ll n;ll k;cin>>n>>k;
	if(n*(n+1)/2>k){
		cout<<-1;return 0;
	}
	if(n*(n+1)/2==k){
		cout<<k<<endl;
		rep(i,1,n)cout<<i<<' ';cout<<endl;
		rep(i,1,n)cout<<i<<' ';cout<<endl;
		return 0;
	}
	ll x=k-n*(n+1)/2;
	rep(i,1,n)a[i]=b[i]=i;
	rep(i,1,n){
		if(i>=n+1-i) break;
		ll y=b[n+1-i]-a[i];
		if(x>y){
			x-=y;swap(b[i],b[n+1-i]);
		}
		else if(x==y){
			x=0;swap(b[i],b[n+1-i]);break;
		}
		else{
			swap(b[i],b[i+x]);x=0;break;
		}
	}
		cout<<k-x<<endl;
		rep(i,1,n)cout<<a[i]<<' ';cout<<endl;
		rep(i,1,n)cout<<b[i]<<' ';cout<<endl;
	
	return 0;
}
