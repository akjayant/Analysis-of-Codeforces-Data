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
ll a[100005],b[100005],num[100005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri n;ll k;cin>>n>>k;
	rep(i,1,n)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	ri m=unique(b+1,b+n+1)-b-1;
	if(m==1){
		cout<<0;return 0;
	}
	rep(i,1,n) ++num[lower_bound(b+1,b+m+1,a[i])-b];
	ri l=1,r=m;
	while(l<r){
		if(num[l]<num[r]){
			ll x=num[l]*(b[l+1]-b[l]);
			if(x<k){k-=x;num[l+1]+=num[l];++l;}
			else if(x==k){
				cout<<max(0LL,b[r]-b[l+1]);
				return 0;
			}
			else{
				ll y=k/num[l];
				cout<<max(0LL,b[r]-b[l]-y);
				return 0;
			}
		}
		else{
			ll x=num[r]*(b[r]-b[r-1]);
			if(x<k){k-=x;num[r-1]+=num[r];--r;}
			else if(x==k){
				cout<<max(0LL,b[r-1]-b[l]);
				return 0;
			}
			else{
				ll y=k/num[r];
				cout<<max(0LL,b[r]-b[l]-y);
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
