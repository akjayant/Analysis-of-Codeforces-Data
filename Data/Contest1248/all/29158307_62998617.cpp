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

//
//ll n, m;
//cin >> n >> m;
//
//dp[1][0] = 1;
//
//for (int i = 2; i < MAXN; ++i) {
//dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
//dp[i][1] = dp[i - 1][0];
//}
//
//ll answr = dp[n][0] + dp[n][1] + dp[m][0] + dp[m][1] - 1;
//answr %= mod;
//answr += mod;
//answr %= mod;
//answr *= 2;
//answr %= mod;
//
//cout << answr;

string s;

int pref[1000];

int n;
int check(int l , int r) {
  int sm = 0;

  pref[0] = 0;

  int mn = 0;

  for (int i = 1; i <= n; ++i) {

    char ch = s[i - 1];

    if (i - 1 == l) {
      ch = s[r];
    } else if (i - 1 == r) {
      ch = s[l];
    }
    pref[i] = pref[i - 1] + (ch == '(' ? 1 : -1);

    mn = min(mn, pref[i]);
  }

  int ret = 0;

  for (int i = 0; i < n; ++i) {
    if (pref[i] == mn)
      ret++;
  }

  return ret;
}

void solve() {

  cin >> n;

  cin >> s;
  int min_ans = 0;
  pair<int, int> answr = {1 , 1};

  int all = 0;

  for (auto el : s){
    if (el == ')')
      all --;
    else
      all++;
  }

  if (all != 0){
    cout << "0\n1 1\n";
    return;
  }

  for (int i = 0; i < n; ++ i){
    for (int j = 1 + i; j < n; ++ j){

      int val = check(i, j);
      if (val > min_ans){
        min_ans = val;
        answr = {i + 1, j + 1};
      }
    }
  }


  cout << min_ans << "\n";

  cout << answr.first << " " << answr.second << "\n";
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