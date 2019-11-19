/*input
3
2 1
1 2
3 3
23 2 23
3 2 3
*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
#define endl '\n'
using namespace std;
// #define int ll
// #pragma GCC optimize("Ofast")

//coding in car is hard

struct Edge{
	Edge(ll i, ll j, ll cost) : i(i), j(j), cost(cost){}
	ll i, j;
	ll cost;
};
template<int N>
struct DSU{
    int parent[N];
    int r[N];
    DSU(){
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
        fill(r, r + N, 0);
    }
    int get(int i){
        return parent[i] == i ? i : parent[i] = get(parent[i]);
    }
    bool is(int i, int j){
        return get(i) == get(j);
    }
    void join(int i, int j){
        int pi = get(i);
        int pj = get(j);

        if(pi != pj){
            if(r[pi] > r[pj]){
                parent[pj] = pi;
            } else if(r[pi] < r[pj]){
                parent[pi] = pj;
            } else {
                parent[pj] = pi;
                r[pi]++;
            }
        }
    }
};
int32_t main(){
	int n;
	cin >> n;

	pii a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
	}

	vector<Edge> e;

	ll c[n], k[n];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> k[i];

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ll len = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y); 
			len *= (k[i] + k[j]);
			e.emplace_back(i  + 1, j + 1, len);
		}
	}

	for(int i = 0; i < n; i++){
		e.emplace_back(0, i + 1, c[i]);
	}

	sort(all(e), [](Edge a, Edge b){
		return a.cost < b.cost;
	});

	DSU<3000> dsu;

	vector<pii> anse;
	vector<int> ans;
	ll total = 0;

	for(auto i : e){
		if(dsu.is(i.i, i.j) == false){
			if(i.i == 0){
				ans.push_back(i.j);
			} else {
				anse.push_back({i.i, i.j});
			}
			dsu.join(i.i, i.j);
			total += i.cost;
		}
	}

	cout << total << endl;
	cout << ans.size() << endl;
	for(int i : ans){
		cout << i << " ";
	}
	cout << endl;
	cout << anse.size() << endl;
	for(pii i : anse){
		cout << i.x << " " << i.y << endl;
	}




}
