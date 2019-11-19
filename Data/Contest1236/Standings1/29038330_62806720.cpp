#include<bits/stdc++.h>
#define REP(i,j,k) for(int i=j;i<k;++i)
#define RREP(i,j,k) for(int i=(int)j-1;i>=k;--i)
#define int long long
#define pb emplace_back
#define P pair<int,int>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define sz(a) (int)(a).size()
#define MX 100005
#define oo 1e18
#define L d*2
#define R (d*2+1)
#define mid (l+r>>1)
#define Ls l,mid,d*2
#define Rs mid+1,r,d*2+1
#define MIN(x,y) (x=min(x,(y)))
#define MAX(x,y) (x=max(x,(y)))
#define mo (int)(1e9+7)
#define IOS cin.tie(0) ,cout.tie(0), cout.sync_with_stdio(0)
using namespace std;
int n,m,k,cnt=1,a,b,c,de,x,y,l,r,u,d;
vector<int> X[MX],Y[MX];
main(){
	IOS;
	cin>>n>>m>>k,l = -1,u = 0,r = m,d = n;
	REP(i,0,n) X[i].pb(-1),X[i].pb(m);
	REP(i,0,m) Y[i].pb(-1),Y[i].pb(n);
	REP(i,0,k) cin>>a>>b,a--,b--,X[a].pb(b),Y[b].pb(a);
	REP(i,0,n) sort(ALL(X[i]));
	REP(i,0,m) sort(ALL(Y[i]));
	while(1){
		if(de==0){
			c = min(r,*lower_bound(ALL(X[x]),y))-1-y;
			y += c, MIN(r,y);
		}
		if(de==1){
			c = min(d,*lower_bound(ALL(Y[y]),x))-1-x;
			x += c, MIN(d,x);
		}
		if(de==2){
			c = max(l,*(--lower_bound(ALL(X[x]),y)))+1-y;
			y += c, MAX(l,y);
		}
		if(de==3){
			c = max(u,*(--lower_bound(ALL(Y[y]),x)))+1-x;
			x += c, MAX(u,x);
		}
		cnt += abs(c);
		if(c==0){
			if(x==0 && y==0){
				if(de) break;
			}
			else break;
		}
		de = (de+1)%4;
	}
	cout<<(cnt+k==n*m?"Yes":"No");
}


