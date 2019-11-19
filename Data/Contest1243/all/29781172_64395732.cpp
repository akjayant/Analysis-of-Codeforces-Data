#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sc(a) scanf("%d", &a)
#define sc2(a, b) sc(a), sc(b)
#define pri(x) printf("%d\n", x)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vector<int> g[100010];
int comp[100010];
bool vis[100010];
bool skip[100010];
int t = 0;
int main(){ _
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
   }
   bool valid = true;
   set<int> out;
   for(int i = 1; i <= n; i++) out.insert(i);
   for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
         queue<int> q;
         q.push(i);
         out.erase(i);
         vis[i] = true;
         ll edges = 0;
         ll sz = 0;
         while(!q.empty()) {
            int u = q.front();
            q.pop();
            comp[u] = t;
            edges += g[u].size();
            sz ++;
            for(auto adj : g[u]) {
               if(!vis[adj]) {
                  skip[adj] = true;
               }
            }
            vector<int> aux;
            for(auto k: out) {
               if(!skip[k]) {
                  aux.pb(k);
                  vis[k] = true;
                  q.push(k);
               }
            }
            for(auto x: aux)
               out.erase(x);
            for(auto adj : g[u]) {
               if(!vis[adj]) {
                  skip[adj] = false;
               }
            }
         }
         t++;
      }
   }
   cout << t-1 << endl;
}
