#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
typedef set <int> si;
typedef map <int, int> mii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vector <int>> vvi;  
#define F(i, a, b) for(int i = a; i <= (int)b; i++)
#define f(i, a, b) for(int i = a; i >= (int)b; i--)
#define F2(i, a, b) for(int i = a; i <= (int)b; i+=2)
#define f2(i, a, b) for(int i = a; i >= (int)b; i-=2)
#define wh(n) int iteration = n; while(iteration--) 
#define For(t, it) for(auto it = (t).begin(); it != (t).end(); ++it)
#define IN insert
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define RS resize
#define GRAF(n) vvi gr; gr.resize(n+1); vector <bool> was; was.resize(n+1, 0);

ll ko[2019][2];
ll c[2019];
ll k[2019];
ll w[2019][2019];

ll dist(int i, int j){
	ll dx = abs(ko[i][0] - ko[j][0]);
	ll dy = abs(ko[i][1] - ko[j][1]);
	return dx + dy;
}

vi es;
vector <pii> kab;
bool was[2019];
ll ans = 0;

ll anv[2019];
int par[2019];
set <pair<ll, int>> ver;
	
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	F(i, 1, n)
		cin >> ko[i][0] >> ko[i][1];
	F(i, 1, n)
		cin >> c[i];
	F(i, 1, n)
		cin >> k[i];
	F(i, 1, n){
		F(j, i+1, n){
			w[i][j] = dist(i, j)*1ll*(k[i] + k[j]);
			w[j][i] = w[i][j];		
		}
	}
	/*F(i, 0, v.size()-1){
		int cur = v[i].second;
		ll mn = v[i].first;
		int ind = 0;
		F(i, 1, n){
			if(i == cur) continue;
			if(was[i] && w[cur][i] <= mn){ 
				mn = w[cur][i];
				ind = i;
			}
		}
		ans += mn;
		if(!ind)
			es.PB(cur);
		else
			kab.PB(MP(cur, ind));
		was[cur] = 1;	 
	}*/
	F(i, 1, n){ 
		anv[i] = c[i];
		ver.IN(MP(anv[i], i));
	}
	//par[s] = 0;
	while(!ver.empty()){
		auto it = ver.begin();
		int cur = (*it).second;
		if(was[cur]){
			ver.erase(it);
			continue;
		}
		ans += anv[cur];
		if(par[cur]) 
			kab.PB(MP(par[cur], cur));
		else 
			es.PB(cur);
	        ver.erase(it);
	        was[cur] = 1;
	        F(i, 1, n){
	        	if(was[i]) continue;
	        	if(w[cur][i] < anv[i]){
	                	anv[i] = w[cur][i];
	                	par[i] = cur;
	                	ver.IN(MP(anv[i], i));
	                }  
	        }
	}
	cout << ans << '\n';
	cout << es.size() << '\n';
	F(i, 0, es.size()-1)
		cout << es[i] << ' ';
	cout << '\n' << kab.size() << '\n';
	F(i, 0, kab.size()-1)
		cout << kab[i].first << ' ' << kab[i].second << '\n';
	return 0;
}