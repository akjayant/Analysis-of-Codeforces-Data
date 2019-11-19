#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN @
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}


struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool Same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){

	int n;
	cin >> n;
	UnionFindTree uf(n+10);
	int x[n+1], y[n+2];
	int c[n+2], k[n+1];
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
	}
	vector<pair<int, pair<int,int> >> e, g;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int w = abs( x[i]-x[j] )+abs(y[i]-y[j]);
			w = w*(k[i]+k[j]);
			e.pb({w,{i,j}});
		}
	}
	sort(all(e));
	for(auto t:e){
		int u = t.sc.fs;
		int v = t.sc.sc;
		if(uf.Same(u,v))continue;
		uf.unite(u,v);
		g.pb(t);
	}
	for(int i=1;i<=n;i++){
		g.pb({c[i],{i,i}});
	}
	sort(all(g));
	vector<int> ans1;
	vector<pair<int,int>> ans2;
	int ans = 0;
	int cnt = 0;
	UnionFindTree uf1(n+100);
	int done[n+10]={0};
	for(int i=0;;i++){
		int u = g[i].sc.sc;
		int v = g[i].sc.fs;
		if(u==v){
			if(!done[uf1.find(u)])
				{ans1.pb(u);cnt++;done[uf1.find(u)]=1;
						ans+= g[i].fs;}
		}
		else {
			int x = done[uf1.find(u)];
			int y = done[uf1.find(v)];
			if( !done[uf1.find(u)] || !done[uf1.find(v)] ){
				ans2.pb({u,v});
				uf1.unite(u,v);
				if( x || y ){
					done[uf1.find(u)]=1;
				}
				cnt++;
				ans+= g[i].fs;
			}
		}
		if(cnt>=n)break;
	}
	cout << ans << endl;
	cout << ans1.size() << endl;
	for(auto t:ans1){
		cout << t << " ";
	}
	cout << endl;
	cout << ans2.size() << endl;
	for(auto t:ans2){
		cout << t.fs << " " << t.sc << endl;
	}
 
}



signed main(){

#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#endif

ios::sync_with_stdio(false);
cin.tie(0);

cout.precision(8);

  int t = 1;
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
