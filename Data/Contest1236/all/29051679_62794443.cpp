/*

“ Remember, Hope is a good thing,
  maybe the best of things,
  and no good thing ever dies.”

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
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
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

const int N = 305;
int a[N][N], i, j, n, m;

void solve()
{
     cin >> n;
     int cnt = 0;
     for (i = 1; i <= n; i++)
     {
          if (i & 1)
          {
               for (j = 1; j <= n; j++)
                    a[j][i] = ++cnt;
          }
          else
          {
               for (j = n; j >= 1; j--)
                    a[j][i] = ++cnt;
          }
     }

     for (i = 1; i <= n; i++)
     {
          for (j = 1; j <= n; j++)
               cout << a[i][j] << " "; cout << endl;
     }

}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif

     solve();

     return 0;
}