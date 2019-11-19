#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2010;
typedef tuple<ll, int, int> t3;

vector<t3> e;
ll x[N], y[N], c[N], k[N]; int n,p[N];
vector<int> vans; vector<pair<int,int> > eans;

ll mh (ll x1, ll y1, ll x2, ll y2) {return abs(x1-x2)+abs(y1-y2);}
int findset(int u) {return p[u]==u?u:p[u]=findset(p[u]);}
bool unionset (int u, int v) {
	int x=findset(u), y=findset(v);
	if (x==y) return false;
	p[x]=y;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1; i<=n; ++i) {
		cin>>x[i]>>y[i];
	}
	for (int i=1; i<=n; ++i) cin>>c[i];
	for (int i=1; i<=n; ++i) cin>>k[i];

	for (int i=1; i<=n; ++i) {
		p[i]=i;
		e.push_back({c[i],0,i});
	}
	for (int i=1; i<=n; ++i)
	for (int j=i+1; j<=n; ++j)
		e.push_back({(k[i]+k[j])*mh(x[i],y[i],x[j],y[j]),i,j});
	sort(e.begin(), e.end());
	ll yen=0;
	for (auto x : e) {
		ll cst; int u,v;
		tie(cst, u, v) = x;
		if (unionset(u,v)) {
			yen+=cst;
			if (u==0) vans.push_back(v);
			else eans.push_back({u,v});
		}
	}
	cout<<yen<<endl;
	cout<<vans.size()<<endl;
	for (int x : vans) cout<<x<<" "; cout<<endl;
	cout<<eans.size()<<endl;
	for (auto x : eans) cout<<x.first<<" "<<x.second<<endl;
	return 0;
}