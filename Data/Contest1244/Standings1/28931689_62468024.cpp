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
		ri n;cin>>n;
		string s;cin>>s;s=' '+s;
		ri ans=n;
		rep(i,1,n){
			if(s[i]=='1'){
				ans=max(ans,n+1);
				ans=max(ans,i*2);
				ans=max(ans,(n-i+1)*2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
