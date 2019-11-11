#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define FI(i,n) for(int i=0;i<=n;i++)
#define TR(x) cout << #x << " = " << x << endl
#define FE(k) get<0>(k)
#define SE(k) get<1>(k)
#define TH(k) get<2>(k)
#define TRAV(a, x) for(auto &a: x)
#define _ << " " <<
#define INF 1E9
#define INF64 1E18

using namespace std;

template<class T1, class T2> void pr(const pair<T1,T2>& x);
template<class T, size_t SZ> void pr(const array<T,SZ>& x);
template<class T> void pr(const vector<T>& x);
template<class T> void pr(const set<T>& x);
template<class T1, class T2> void pr(const map<T1,T2>& x);
template<class T> void pr(const T& x) { cout << x; }
template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
  pr(first); pr(rest...);
}
template<class T1, class T2> void pr(const pair<T1,T2>& x) {
  pr("{",x.first,", ",x.second,"}");
}
template<class T> void prContain(const T& x) {
  pr("{");bool fst = 1; TRAV(a,x) pr(!fst?", ":"",a), fst = 0;pr("}");
}
template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
template<class T> void pr(const vector<T>& x) { prContain(x); }
template<class T> void pr(const set<T>& x) { prContain(x); }
template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

void ps() { pr("\n"); }
template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
  pr(first," "); ps(rest...); // print w/ spaces
}

template<typename T> int remin(T& a,const T& b){if(b<a){a=b;return true;}return false;}
template<typename T> int remax(T& a,const T& b){if(b>a){a=b;return true;}return false;}

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int T, N, r, p, s;
string str;
vi cnt(3);
map<char, int> m = { {'R', 0}, {'P', 1}, {'S', 2}};

int main(int argc, const char **argv) {
  scanf("%d", &T);
  for (int tt = 0; tt < T; ++tt) {
    for (int i = 0; i < 3; ++i) cnt[i] = 0;
    scanf("%d", &N);
    scanf("%d%d%d\n", &r, &p, &s);
    cin >> str;
    for (int i = 0; i < N; ++i) {
      cnt[m[str[i]]]++;
    }
    // ps(cnt);
    int total = 0;
    int pp = min(p, cnt[0]);
    int ss = min(s, cnt[1]);
    int rr = min(r, cnt[2]);
    total += pp; // R
    total += ss;
    total += rr;
    if (total >= (N + 1) / 2) {
      ps("YES");
      string ans(N, ' ');
      for (int i = 0; i < N; ++i) {
        if (ans[i] != ' ') continue;
        if (str[i] == 'R' && pp) {
          ans[i] = 'P';
          --pp; --p;
        }
        if (str[i] == 'P' && ss) {
          ans[i] = 'S';
          --ss; --s;
        }
        if (str[i] == 'S' && rr) {
          ans[i] = 'R';
          --rr; --r;
        }
      }
      for (int i = 0; i < N; ++i) {
        if (ans[i] != ' ') continue;
        if (p) { ans[i] = 'P'; --p; continue; }
        if (s) { ans[i] = 'S'; --s; continue; }
        if (r) { ans[i] = 'R'; --r; continue; }
      }
      assert(p + s + r == 0);
      ps(ans);
    } else {
      ps("NO");
    }
  }
  return 0;
}
