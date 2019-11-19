#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int n;
string s;

void solveCase() {
  cin >> n >> s;
  if (l(s) != n) throw 1;
  int ans = n;
  int md = 0;
  rep(i, n) {
    if (s[i] == '1') {
      md = max(md, i+1);
      md = max(md, n-i);
    }
  }
  ans = max(ans, md*2);
  cout << ans << endl;
}

void solution()
{
  int t;
  cin >> t;
  while (t--) {
    solveCase();
  }
}
 
int main()
{
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
#endif
  solution();
  return 0;
}