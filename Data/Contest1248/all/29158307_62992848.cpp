#pragma comment(linker, "/STACK:33554432")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<long long, long long>;

void precalc()
{
}

ll mod = 1e9 + 7;

const int MAXN = 1e5  +20;

ll dp[MAXN][2];

void solve() {

  ll n, m;
  cin >> n >> m;

  dp[1][0] = 1;

  for (int i = 2; i < MAXN; ++i) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    dp[i][1] = dp[i - 1][0];
  }

  ll answr = dp[n][0] + dp[n][1] + dp[m][0] + dp[m][1] - 1;
  answr %= mod;
  answr += mod;
  answr %= mod;
  answr *= 2;
  answr %= mod;

  cout << answr;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    precalc();
    solve();
#ifndef ONLINE_JUDGE
    cout << '\n' << (double)clock() / CLOCKS_PER_SEC << '\n';
#endif

}