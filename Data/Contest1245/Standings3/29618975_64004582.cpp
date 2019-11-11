/*
Author: WangXP
Date:
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inc(i,n) for (int i=0;i<n;i++)
#define icc(i,n) for (int i=1;i<=n;i++)
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rpp(i,a,b) for (int i=a;i<=b;i++)
#define dec(i,n) for (int i=n-1;i>=0;i--)
#define dcc(i,n) for (int i=n;i;i--)
ll rd(){
	ll x=0,f=1;char c=getchar();
	while (!isdigit(c) && c!='-') c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N=110;

char s[N],ans[N];
bool vis[N];

int main(){
	int t; cin>>t;
	while (t--){
		memset(vis,0,sizeof vis);
		int n; cin>>n;
		int a,b,c; cin>>a>>b>>c>>s;
		int d=0;
		inc(i,n){
			if (s[i]=='R'){
				if (b) ans[i]='P',b--,d++,vis[i]=1;
			}
			if (s[i]=='P'){
				if (c) ans[i]='S',c--,d++,vis[i]=1;
			}
			if (s[i]=='S'){
				if (a) ans[i]='R',a--,d++,vis[i]=1;
			}
		}
		ans[n]=0;
		inc(i,n){
			if (!vis[i]){
				if (a) ans[i]='R',a--;
				else if (b) ans[i]='P',b--;
				else ans[i]='S';
			}
		}
		if (d>=(n+1)/2)
		cout<<"YES\n"<<ans<<'\n';
		else cout<<"NO\n";
	}	
	return 0;
}
