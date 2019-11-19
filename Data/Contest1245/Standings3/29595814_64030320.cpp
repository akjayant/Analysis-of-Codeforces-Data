/*

  When a bird is alive.. it eats Ants.
  When the bird is dead.. Ants eat the bird.

  One tree makes a million match sticks …
  Only one match stick needed to burn a million trees …
  So be good and do good.

  Time and circumstances can change at any time.
  Don’t devalue or hurt anyone in life.

  You may be powerful today. But remember.
  Time is more powerful than You!

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int             long long int
#define ld              long double
#define F               first
#define S               second
#define pb              push_back
#define si              set <int>
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define vpp             vector <pair<int, pii>>
#define pip             pair<int,pair<int,int>>
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <pip, vpp, greater<pip>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x +1<< " "; cout << endl
#define Print(a,x,y)    for (int i=x; i<y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 2005;
vpi v[N], foo, ee;
vi vv;
int done[N], ans, i, j;
int a[N], b[N], c[N], d[N], n, m;
que_min Q;

void answer()
{
     cout << ans << endl;
     cout << sz(vv) << endl;
     print(vv);
     cout << sz(foo) << endl;
     for (auto x : foo)
          cout << x.F + 1 << " " << x.S + 1 << endl;
}
void bfs()
{
     while (!Q.empty())
     {
          pip p = Q.top();
          Q.pop();
          int nw = p.S.F, agee = p.S.S, distance = p.F;
          if (!done[nw])
          {
               if (nw != agee)
                    foo.pb({nw, agee}), ans += distance;
               else
                    vv.pb(nw), ans += distance;
               done[nw] = 1;
               for (i = 0; i < sz(v[nw]); i++)
               {
                    int aa = v[nw][i].F;
                    int bb = v[nw][i].S;
                    if (!done[aa])
                         Q.push({bb, {aa, nw}});
               }
          }
     }
}
void solve()
{
     cin >> n;
     for (i = 0; i < n; i++)
          cin >> a[i] >> b[i];
     for (i = 0; i < n; i++)
          cin >> c[i];
     for (i = 0; i < n; i++)
          cin >> d[i];

     for (i = 0; i < n; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               int sum = (d[i] + d[j]) * (abs(a[i] - a[j]) + abs(b[i] - b[j]));
               v[j].pb({i, sum});
               v[i].pb({j, sum});
          }
          ee.pb({c[i], i});
     }
     sort(all(ee));
     for (i = 0; i < n; i++)
          Q.push({c[i], {i, i}});

     bfs();
     answer();
}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif

     cout << setprecision(9) << fixed;
     clock_t z = clock();
     solve();
     cerr << "Total Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

     return 0;
}