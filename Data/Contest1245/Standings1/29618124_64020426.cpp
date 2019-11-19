#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> piii;
typedef double lf;

const int N = 2000+2;
const int MOD = 1e9+7;
const ll oo = 1e18;

ll x[N], y[N], k[N];
int f[N];
int find(int x) { return f[x] = x == f[x] ? x : find(f[x]); }
void merge(int a, int b) {
  f[find(a)] = find(b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #else
    #define endl '\n'
  #endif

  int n;
  while(cin >> n) {
    iota(f, f+n+1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
    }
    vector<piii> edges;
    for(int i = 1; i <= n; i++) {
      int ci; cin >> ci;
      edges.push_back({ci, {0, i}});
    }

    for(int i = 1; i <= n; i++) {
      cin >> k[i];
    }
    
    for(int i = 1; i <= n; i++ ) {
      for(int j = 1; j <= n; j++) {
        edges.push_back({(abs(x[i] - x[j])+abs(y[i]-y[j])) * (k[i]+k[j]), {i, j}});
      }
    }

    sort(edges.begin(), edges.end());
    ll cost = 0;
    vector<int> stations;
    vector<pii> connections;
    for(auto &e : edges) {
      int a = e.second.first;
      int b = e.second.second;
      ll c = e.first;
      if(find(a) == find(b)) continue;
      merge(a, b);
      if(a == 0) stations.push_back(b);
      else if(b == 0) stations.push_back(a);
      else connections.push_back({a, b});
      cost += c;
    }
    cout << cost << endl;
    cout << stations.size() << endl;
    for(auto &e : stations) cout << e << " ";
    cout << endl;
    cout << connections.size() << endl;
    for(auto &e : connections) cout << e.first << " " << e.second << endl;

  }
  
}