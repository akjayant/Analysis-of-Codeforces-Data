#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;
int pai[MAXN];

void init(int n){
	for(int i=0; i<=n; i++){
		pai[i]=i;
	}
}

int find(int i){
	if(pai[i]==i)return i;
	return pai[i]=find(pai[i]);
}

int join(int a, int b){
	a=find(a);
	b=find(b);
	pai[a]=pai[b];
}
ll n, x[MAXN], y[MAXN], c[MAXN], k[MAXN], yen;

vector<pair<ll, pii> > v;
vector<pii> ans;
vector<int> po;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> c[i];
    	v.pb({c[i], {i, n}});
    }
    for(int i = 0; i < n; i++){
    	cin >> k[i];
    }

    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		v.pb({(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]), {i, j}});
    	}
    }
    sort(v.begin(), v.end());
    for(auto p : v){
    	if(find(p.se.fi) == find(p.se.se)) continue;
    	join(p.se.fi, p.se.se);
    	yen += p.fi;
    	if(p.se.se == n) po.pb(p.se.fi);
    	else ans.pb({p.se.fi, p.se.se});
    }
    cout << yen << endl;
    cout << po.size() << endl;
    for(auto p : po) cout << p + 1 << " ";
    cout << endl << ans.size() << endl;
    for(auto p : ans){
    	cout << p.fi + 1 << " " << p.se + 1 << endl;
    }
}