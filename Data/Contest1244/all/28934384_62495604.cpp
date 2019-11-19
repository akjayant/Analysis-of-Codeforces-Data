#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int maxn = 200022;

int n;
ll k;
int a[maxn];

int main()
{

  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n);

  int l = 0, r = n - 1;
  ll c = 1;
  while (r > l) {
    int d;
    if (l == r - 1) {
      d = a[r] - a[l];
    } else if (l == r - 2) {
      d = a[r] - a[l];
    } else {
      d = a[l + 1] - a[l] + a[r] - a[r - 1];
    }

    // cerr << d << " " << c << " " << k << endl;

    if (k >= c * d) {
      k -= c * d;
      l++, r--;
      c++;
      continue;
    }

    cout << a[r] - a[l] - k / c << endl;
    return 0;
  }

  cout << 0 << endl;
  return 0;
}