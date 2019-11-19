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

const int N=4e5+5;
bool vis[N];
int a[N],b[N];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri n,k;cin>>n>>k;
	string s;cin>>s;s=' '+s+s;
	ri x=1;
	while(x<n&&s[x]==s[n]) ++x;
	if(x==n){
		rep(i,1,n)cout<<s[i];return 0;
	}
	rep(i,x,x+n-1){
		ri j=i;
		while(j+1<=x+n-1&&s[j+1]==s[j]) ++j;
		if(j!=i){
			rep(l,i,j) vis[l]=1;
		}
		i=j;
	}
	ri pos=x;
	while(pos<=n+x-1&&!vis[pos]){
		++pos;
	}
	if(pos>n+x-1){
		if(k&1)
		rep(i,1,n)cout<<(char)('W'+'B'-s[i]);
		else rep(i,1,n)cout<<s[i];return 0;
	}
	ri lst=pos,d=0;
	rep(i,1,n){
		++pos;++d;if(pos==x+n) pos=x;
		if(vis[pos]) lst=pos,d=0;
		else a[pos]=lst,b[pos]=d;
	}
	pos=x;
	while(pos<=n+x-1&&!vis[pos]){
		++pos;
	}
	lst=pos,d=0;
	rep(i,1,n){
		--pos;++d;if(pos<x) pos=x+n-1;
		if(vis[pos]) lst=pos,d=0;
		else{
			if(d<b[pos]) a[pos]=lst,b[pos]=d;
		}
	}
	rep(i,n+1,x+n-1){
		if(vis[i]) cout<<s[i];
		else{
			if(b[i]<=k) cout<<s[a[i]];
			else{
				if(k&1) cout<<(char)('W'+'B'-s[i]);
				else cout<<s[i];
			}
		}
	}
	rep(i,x,n){
		if(vis[i]) cout<<s[i];
		else{
			if(b[i]<=k) cout<<s[a[i]];
			else{
				if(k&1) cout<<(char)('W'+'B'-s[i]);
				else cout<<s[i];
			}
		}
	}
	return 0;
}
