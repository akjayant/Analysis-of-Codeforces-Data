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
	ri t;cin>>t;
	while(t--){
		ri a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		if(a%c==0) a/=c;
		else a=a/c+1;
		if(b%d==0) b/=d;
		else b=b/d+1;
		if(a+b<=k) cout<<a<<' '<<b<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
