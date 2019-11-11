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

const int N = 200005;
int a[N], dp[N], i, j, n, m;
string s;

int mod = 1e9 + 7;
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
inline int powr(int a, int b) {
     int x = 1 % mod;
     while (b) {
          if (b & 1) x = mul(x, a);
          a = mul(a, a);
          b >>= 1;
     }
     return x;
}
inline int inv(int a) { return powr(a, mod - 2); }

void solve()
{
     cin >> s;
     cin >> s;
     n = s.size();
     for (i = 0; i < n; i++)
     {
          if (s[i] == 'm' || s[i] == 'w')
          {
               cout << 0;
               return ;
          }
     }
     dp[0] = 1;
     for (i = 1; i < n; i++)
     {
          if (s[i] == 'u' && s[i - 1] == 'u' || s[i] == 'n' && s[i - 1] == 'n')
          {
               if (i - 2 == -1)
                    dp[i]++;
               else
                    dp[i] = add(dp[i], dp[i - 2]);
          }
          dp[i] = add(dp[i], dp[i - 1]);
     }
     cout << dp[n - 1];
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