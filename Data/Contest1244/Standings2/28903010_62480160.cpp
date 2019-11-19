#include <bits/stdc++.h>
 
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("anime.in", "r", stdin); freopen("anime.out", "w", stdout);

typedef long long ll;
typedef long double ld;
 
using namespace std;

vector<int> fst;
vector<int> snd;
vector<int> thr;
vector<vector<int>> g;
vector<int> v;
vector<int> used;
vector<int> answer;

const ll inf = 1e18 + 7;
ll now = 0;

void dfs(int ve, int c){
	used[ve] = 1;
	int cnt = v[c % 3];
	answer[ve] = cnt + 1;
	if (cnt == 0){
		now += fst[ve];
	}if (cnt == 1){
		now += snd[ve];
	}if (cnt == 2){
		now += thr[ve];
	}
	for (auto u : g[ve]){
		if (!used[u]){
			dfs(u, c + 1);
		}
	}
}

signed main(){
	ios;
	/*
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	ll kolvo_w = (p + w - 1) / w;
	ll delt = w - d;
	ll kolvo_d = (kolvo_w * w - p) / delt;
	kolvo_w -= kolvo_d;
	ll ans = kolvo_w * w + kolvo_d * d;
	if (ans != p || n < (kolvo_w + kolvo_d)){
		cout << -1 << endl;
	}else{
		n = n - kolvo_w - kolvo_d;
		cout << kolvo_w << ' ' << kolvo_d << ' ' << n << endl;
	}*/
	int n, a, b;
	cin >> n;
	fst.resize(n);
	answer.resize(n);
	for (int i = 0; i < n; i++)
		cin >> fst[i];
	snd.resize(n);
	for (int i = 0; i < n; i++)
		cin >> snd[i];
	thr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> thr[i];
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n - 1; i++){
		cin >> a >> b;
		g[a - 1].pb(b - 1);
		g[b - 1].pb(a - 1);
	}
	int start = 0;
	for (int i = 0; i < n; i++){
		if (g[i].size() == 1){
			start = i;
		}
		if (g[i].size() > 2){
			cout << -1;
			return 0;
		}
	}
	ll mn = inf;
	vector<int> ans;
	for (int one = 0; one < 3; one++){
		for (int two = 0; two < 3; two++){
			for (int three = 0; three < 3; three++){
				if (one != two && two != three && one != three){
					v.pb(one);
					v.pb(two);
					v.pb(three);
					dfs(start, 0);
					if (now < mn){
						ans = v;
					}
					mn = min(mn, now);
					v.clear();
					now = 0;
					for (int i = 0; i < n; i++)
						used[i] = 0;
				}
			}
		}
	}
	v = ans;
	dfs(start, 0);
	cout << mn << endl;
	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
}