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
int a[100005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri n;cin>>n;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	ri m=n/2;ll s1=0,s2=0;
	rep(i,1,m) s1+=a[i];
	rep(i,m+1,n) s2+=a[i];
	cout<<s1*s1+s2*s2;
	return 0;
}
