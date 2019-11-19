#include<bits/stdc++.h>

using namespace std;


#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e5 + 1, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int a[N], b[N], c[N], kol = 0, sum = 0;
vi g[N];
int ans[7][N];

void dfs (int v, int p, int c1, int c2) {
    for (auto to : g[v]) {
        if (to == p) continue;
        if (c1 == 1 && c2 == 2) {
           sum+= c[to];
        ans[kol][to] = 3;
           dfs(to, v, 3, c1);
        }
        if (c1 == 1 && c2 == 3) {
            sum+= b[to];
        ans[kol][to] = 2;
            dfs(to, v, 2, c1);
        }
        if (c1 == 2 && c2 == 1) {
            sum+= c[to];
        ans[kol][to] = 3;
            dfs(to, v, 3, c1);
        }
        if (c1 == 2 && c2 == 3) {
             sum+= a[to];
        ans[kol][to] = 1;
            dfs(to, v, 1, c1);
        }
        if (c1 == 3 && c2 == 1) {
            sum+= b[to];
            ans[kol][to] = 2;
            dfs(to, v, 2, c1);
        }
        if (c1 == 3 && c2 == 2) {
            sum+= a[to];
            ans[kol][to] = 1;
            dfs(to, v, 1, c1);
        }
    }
}

signed main() {
   #ifdef Flash
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
        cin >> a[i];
   }
   for (int i = 1; i <= n; i++) {
        cin >> b[i];
   }
   for (int i = 1; i <= n; i++) {
        cin >> c[i];
   }

   for (int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        g[l].pb(r);
        g[r].pb(l);
   }
   int st = -1;
   for (int i = 1; i <= n; i++) {
        if (g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
        if (g[i].size() == 1) st = i;
   }
   int ans1 = INF, ot;
   for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j != i)  {
                sum = 0;
                int v = st, u = g[st][0];
                if (i == 1) {
                   ans[kol][v] = 1, sum+= a[v];
                }
                if (i == 2) {
                    ans[kol][v] = 2, sum+= b[v];
                }
                if (i == 3) ans[kol][v] = 3, sum+= c[v];

                if (j == 1) ans[kol][u] = 1, sum+= a[u];
                if (j == 2) ans[kol][u] = 2, sum+= b[u];
                if (j == 3) ans[kol][u] = 3, sum+= c[u];

                dfs(u, v, ans[kol][u], ans[kol][v]);
                if (sum < ans1) {
                    ans1 = sum;
                    ot = kol;
                }
                kol++;
            }
        }
   }
   cout << ans1 << "\n";
   for (int i = 1; i <= n; i++) cout << ans[ot][i] << ' ';



}
