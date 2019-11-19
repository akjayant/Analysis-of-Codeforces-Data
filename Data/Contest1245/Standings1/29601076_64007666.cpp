#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define INF 1e9+7
#define pf2 pop_front
#define pb2 pop_back
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz size
#define eps 1e-7
#define fod find_by_order
#define fastio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ofk order_of_key
#define val(x) cout << "Value dari "<< #x << " adalah " << x  << "\n"
#define tr tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

void readf(string x){
	freopen((x+".in").c_str(),"r",stdin);
	freopen((x+".out").c_str(),"w",stdout);
}

void pr(string x){
	freopen((x+".in").c_str(),"w",stdout);
}


int read()
{
	bool min = 0;
	int  result = 0;
	char ch;
	ch = getchar();
	while(1)
	{
		if(ch == '-') break;
		if(ch >='0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') min = 1;else result = ch-'0';
	while(1)
	{
		ch =getchar();
		if(ch< '0' || ch>'9') break;
		result = result * 10 + (ch-'0');
	}
	if(min) return -result;
	return result;
}
//Reynaldo's Template

const int N = 2005;

ll n;

ll x[N], y[N], c[N], k[N];

vector<ll> nyala;
vector<pair<ll, ll> > kota;


int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	
	priority_queue<pair<ll, pair<ll, ll> > > pq;

	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		pq.push({-c[i], {i, -1}});
		
	}
	
	for(int i = 1; i <= n; i++) cin >> k[i];


	bool vis[N];
	ll ans = 0;
	memset(vis, 0, sizeof vis);
	
	while(!pq.empty()) {
		int r = pq.top().fi, t = pq.top().se.fi, kota_sebelum = pq.top().se.se;
		pq.pop();
		if (vis[t]) continue;
		vis[t] = 1;
		ans += r;
		
		if (kota_sebelum == -1) {
			nyala.pb(t);
		}
		else {
			kota.pb({kota_sebelum, t});
		}
		
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			
			ll jarak = abs(x[t] - x[i]) + abs(y[t] - y[i]);
			jarak *= (k[t] + k[i]);
			
			pq.push({-jarak, {i, t}});
		}
	}
	
	cout << -ans << "\n";
	cout << nyala.size()<< "\n";
	for(int i = 0; i < nyala.size(); i++) {
		if (i != 0) cout << " ";
		cout << nyala[i];
	}
	cout << "\n";
	cout << kota.size() << "\n";
	for(int i = 0; i < kota.size(); i++) {
		cout << kota[i].fi << " " << kota[i].se << "\n";
	}
	
	
}
