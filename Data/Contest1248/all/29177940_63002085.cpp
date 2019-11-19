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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = -1;
  Pi best;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      sum++;
    else
      sum--;
  }
  if (sum != 0) {
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  vector<int> p(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      swap(s[i], s[j]);
      p[0] = 0;
      vector<int> mins1(n + 1), mins2(n + 1);
      int mn1 = n, mn2 = n;
      int zerocount = 0, minuscount = 0;
      for (int k = 0; k < n; ++k) {
        if (s[k] == '(')
          p[k + 1] = p[k] + 1;
        else
          p[k + 1] = p[k] - 1;
        mn2 = min(mn2, p[k + 1]);
        mins2[k] = mn2;
      }
      for (int k = n - 1; k >= 0; --k) {
        mn1 = min(mn1, p[k + 1]);
        mins1[k] = mn1;
      }
      int ans2 = 0;
      for (int k = 0; k < n; ++k) {
        if (mins1[k] >= p[k + 1] && mins2[k] >= p[k + 1]) {
          ans2++;
        }
      }
      if (ans < ans2) {
        ans = ans2;
        best = Pi(i + 1, j + 1);
      }
      swap(s[i], s[j]);
    }
  }
  cout << ans << endl;
  cout << best.first << " " << best.second << endl;
  return 0;
}