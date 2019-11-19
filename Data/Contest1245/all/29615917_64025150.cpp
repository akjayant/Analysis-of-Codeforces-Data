#include <bits/stdc++.h>

using namespace std;

struct data {
   int u, v;
   long long cost;
   bool operator < (const data &other) const {
      return cost < other.cost;
   }
};

const int maxn = 2002;
int n;
int x[maxn], y[maxn];
int k[maxn];
int par[maxn];
vector<data> edges;

int dis(int i, int j) {
   return (abs(x[i]-x[j]) + abs(y[i]-y[j]));
}

void Input() {
   cin >> n;
   for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
   }
   for (int i = 1; i <= n; i++) {
      data X;
      X.u = 0, X.v = i;
      cin >> X.cost;
      edges.push_back(X);
   }
   for (int i = 1; i <= n; i++) {
      cin >> k[i];
   }
   for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
         data X;
         X.u = i;
         X.v = j;
         X.cost = 1LL * dis(i, j) * (k[i] + k[j]);
         edges.push_back(X);
      }
   }
}

int getroot(int u) {
   if (par[u] < 0) return u;
   return par[u] = getroot(par[u]);
}

void Join(int u, int v) {
   u = getroot(u);
   v = getroot(v);
   par[u] += par[v];
   par[v] = u;
}

void Output() {
   sort(edges.begin(), edges.end());
   memset(par, -1, sizeof(par));
   long long ans = 0;
   vector<int> V;
   vector<pair<int, int>> E;
   for (int i = 0; i < edges.size(); i++) {
      int u = edges[i].u;
      int v = edges[i].v;
      ///cerr << u << " " << v << "--\n";
      if (getroot(u) == getroot(v)) continue;
      if (u == 0 || v == 0) {
         if (u == 0) V.push_back(v);
         else V.push_back(u);
      }
      else {
         E.push_back(make_pair(u, v));
      }
      ans += edges[i].cost;
      Join(u, v);
   }
   cout << ans << "\n";
   cout << V.size() << "\n";
   for (int i = 0; i < V.size(); i++) cout << V[i] << " ";
   cout << "\n";
   cout << E.size() << "\n";
   for (int i = 0; i < E.size(); i++) {
      cout << E[i].first << " " << E[i].second << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   ///freopen ("D.inp", "r", stdin);
   ///freopen ("D.out", "w", stdout);

   Input(); Output();

   return 0;
}
