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

int a, b, c, d, k;

void solveCase() {
  cin >> a >> b >> c >> d >> k;
  int A1 = (a+c-1)/c;
  int A2 = (b+d-1)/d;
  if (A1 + A2 > k) {
    cout << -1 << endl;
  } else {
    cout << A1 << " " << A2 << endl;
  }
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