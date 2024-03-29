#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #pragma comment(linker, "/STACK:667177216")
#define ll long long
#define ull unsigned long long
#define INF 1000000007
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define vI vector<int>
#define vvI vector<vector<int>>
#define vLL vector<LL>
#define vS vector<string>
#define fori(i, n) for (int(i) = 0; (i) < n; (i)++)
#define forn(it, from, to) for (int(it) = from; (it) < to; (it)++)
#define forI(tmp) for (auto(it) = (tmp).begin(); (it) != (tmp).end(); (it)++)
#define PI 3.14159265356
#define LD long double
#define sc(a) scanf("%d", &(a))
#define scLL(a) scanf("%I64d", &(a))
#define mems(a, val) memset(a, val, sizeof(a))
#define sz(a) (int)(a).size()
typedef long long LL;
using namespace std;
const LL MOD = 1000000000 + 7;
const LL MAXN = 2 * 100000 + 100;

LL bpow(LL a, LL p) {
  if (p == 0) return 1;
  LL tmp = bpow(a, p >> 1);
  tmp *= tmp;
  tmp %= MOD;
  if (p&1) tmp *= a;
  tmp %= MOD;
  return tmp;
}

int main() {
#ifdef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  forn(i,0,n) {
    forn(j,0,n) {
      if (j %2 ==  0)
      cout<<j * n + i + 1<<" ";
      else{
      cout<<j * n + (n-1-i) + 1<<" ";
      }
    }

    cout<<endl;
  }

  return 0;
}