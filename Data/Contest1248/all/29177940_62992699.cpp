#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define INF (1 << 29)
#define LLINF (1LL << 60)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;

string to_string(string s) { return s; }

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class S>
string to_string(unordered_set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S, class T>
string to_string(map<S, T> m) {
  string ret = "{";
  for (pair<S, T> x : m) ret += to_string(x) + ",";
  return ret + "}";
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll nm = max(n, m);
  vector<vector<ll>> dp1(nm, vector<ll>(4));
  dp1[0][1] = dp1[0][2] = 1;
  for (int i = 1; i < nm; ++i) {
    dp1[i][0] = dp1[i][3] = dp1[i - 1][1];
    dp1[i][1] = dp1[i][2] = (dp1[i - 1][0] + dp1[i - 1][2]) % MOD;
  }
  ll ans = (accumulate(ALL(dp1[n - 1]), 0LL) % MOD +
            accumulate(ALL(dp1[m - 1]), 0LL) % MOD - 2 + MOD) %
           MOD;
  cout << ans << endl;
  return 0;
}