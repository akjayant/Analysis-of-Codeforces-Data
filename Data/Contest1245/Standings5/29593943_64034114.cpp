#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector < vector <pii> > graph;

vector < pair <ll, pii> > e;
vector <int> x, y, c, k;
vector <int> dsu, sz;

void init(int n){
    dsu.resize(n), sz.resize(n);
    for(int i = 0; i < n; i++){
        dsu[i] = i;
        sz[i] = 1;
    }
}

int get(int v){
    if(v == dsu[v]){
        return v;
    }
    return dsu[v] = get(dsu[v]);
}

void unite(int u, int v){
    u = get(u), v = get(v);
    if(u != v){
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        dsu[u] = v;
        sz[v] += sz[u];
    }
}

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   x.resize(n + 1), y.resize(n + 1), c.resize(n + 1), k.resize(n + 1);
   for(int i = 1; i <= n; i++){
       cin >> x[i] >> y[i];
   }
   for(int i = 1; i <= n; i++){
       cin >> c[i];
   }
   for(int i = 1; i <= n; i++){
       cin >> k[i];
   }
   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++){
           if(i != j){
               ll w = 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
               e.push_back({w, {i, j}});
           }
       }
   }
   for(int i = 1; i <= n; i++){
       e.push_back({c[i], {0, i}});
   }
   sort(all(e));
   init(n + 1);
   ll ans = 0;
   vector < pair <ll, pii> > ans_;
   for(int i = 0; i < e.size(); i++){
       ll w = e[i].f, u = e[i].s.f, v = e[i].s.s;
       if(get(u) != get(v)){
           unite(u, v);
           ans += w;
           ans_.push_back(e[i]);
       }
   }
   cout << ans << '\n';
   int cnt = 0;
   for(int i = 0; i < ans_.size(); i++){
       if(ans_[i].s.f == 0){
           cnt++;
       }
   }
   cout << cnt << '\n';
   for(int i = 0; i < ans_.size(); i++){
       if(ans_[i].s.f == 0){
           cout << ans_[i].s.s << ' ';
       }
   }
   cout << '\n' << int(ans_.size()) - cnt << '\n';
   for(int i = 0; i < ans_.size(); i++){
       if(ans_[i].s.f != 0){
           cout << ans_[i].s.f << ' ' << ans_[i].s.s << '\n';
       }
   }
   return 0;
}
