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

const int maxn = 400022;

int a[maxn];
int b[maxn];
int first[maxn], last[maxn];
int n;

void solve() {
  int n; 
  cin >> n; 
  string s; 
  cin >> s; 


  int ans = n; 
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int cur = 2 * i + 2;
      if (cur > ans) ans = cur;
    }
  }

  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int cur = 2 * i + 2;
      if (cur > ans) ans = cur;
    }
  }

  cout << ans << endl;

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