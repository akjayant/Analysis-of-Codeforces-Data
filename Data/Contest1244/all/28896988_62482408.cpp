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
int n,k,a,l,r;
map<int,int> m;
set<int> s;
set<int,greater<int>> us;
main(){
	IOS;
	cin>>n>>k;
	REP(i,0,n) cin>>a,m[a]++,s.insert(a),us.insert(a);
	while(1){
		l = *s.begin(),r = *us.begin();
		if(l==r) return cout<<0,0;
		if(m[l]<=m[r] && m[l]<=k){
			int ll = min(l+k/m[l],*next(s.begin()));
			k -= (ll-l)*m[l];
			m[ll] += m[l], s.erase(l), s.insert(ll);
		}
		else if(m[r]<m[l] && m[r]<=k){
			int rr = max(r-k/m[r],*next(us.begin()));
			k -= (r-rr)*m[r];
			m[rr] += m[r], us.erase(r), us.insert(rr);
		}
		else return cout<<r-l,0;
	}
}


