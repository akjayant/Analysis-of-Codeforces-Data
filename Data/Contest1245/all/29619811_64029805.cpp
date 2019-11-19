#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It map<ll, ll>::iterator
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

typedef struct{
	ll u, v, dis;
} node;

bool cmp(node a, node b){
	return a.dis<b.dis;
}

const ll N = 2e3+5, mod=1e9+7;
ll n, x[N], y[N], c[N], k[N], f[N];
vector<node> edges;
vector<ll> aa, bb, cc;

ll find(ll x){
	return f[x] = (f[x]==x ? x : find(f[x]));
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n; f[0] = 0;
	for (ll i = 1; i <= n; i++){
		cin>>x[i]>>y[i]; f[i] = i;
	}
	for (ll i = 1; i <= n; i++){
		cin>>c[i]; 
		edges.push_back((node){0, i, c[i]});
	}
	for (ll i = 1; i <= n; i++){
		cin>>k[i];
	}
	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= n; j++){
			if (i != j){
				edges.push_back((node){i, j, (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});		
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	ll ans = 0;
	for (ll i = 0; i < edges.size(); i++){
		ll fu = find(edges[i].u), fv = find(edges[i].v);
		if (fu != fv){
			ans += edges[i].dis;
			f[fu] = fv;
			if (edges[i].u==0 || edges[i].v==0){
				aa.push_back(edges[i].u+edges[i].v);
			}
			else{
				bb.push_back(edges[i].u);
				cc.push_back(edges[i].v);
			}
		}
	}
	cout<<ans<<endl;
	cout<<aa.size()<<endl;
	if (aa.size()){
		for (ll i = 0; i < aa.size(); i++){
			cout<<aa[i]<<" ";
		}
		cout<<endl;	
	}
	cout<<bb.size()<<endl;
	if (bb.size()){
		for (ll i = 0; i < bb.size(); i++){
			cout<<bb[i]<<" "<<cc[i]<<endl;
		}
		cout<<endl;	
	}
	
    return 0;
}