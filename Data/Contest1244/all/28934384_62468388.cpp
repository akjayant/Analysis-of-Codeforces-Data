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

bool check(int tt) {
}

int a, b, c, d, k;

void solve() {
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &k); 

  if (((a + (c - 1)) / c) + ((b + (d - 1)) / d) > k) {
    cout << -1 << endl;
  } else {
    cout << ((a + (c - 1)) / c) << " " <<  ((b + (d - 1)) / d) << endl;
  }
}

int main()
{

  int q;
  scanf("%d", &q); 

  for (int i = 0; i < q; i++) {
    solve();
  }

  return 0;
}