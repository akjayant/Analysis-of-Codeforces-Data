#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

int main(int argc, char *argv[]) {

  i64 k, K;
  cin >> K;
  REP(0, K, k) {
    i64 n, i;
    cin >> n;
    vi a(n);
    REP(0, n, i) {
      cin >> a[i];
    }
    sort(all(a), greater<i64>());
    i64 ans = 0;
    REP(0, n, i) {
      i64 l = i + 1;
      if(a[i] >= l) {
	ans = max(ans, l);
      }
    }
    cout << ans << endl;
  }

  return 0;
}
