// Author: Kamil Nizinski
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(...)
#define cerr if (false) cerr
#define lcl if (false)
#else
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define lcl
#endif
#define ft first
#define sd second
#define psb push_back
#define sz(a) static_cast<int>(a.size())
using namespace std;
typedef int64_t LL;
typedef uint64_t LLU;
typedef double DD;
typedef pair<int, int> PII;

void solve() {
  int n;
  cin >> n;
  vector<int> buckets(10007, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    buckets[a]++;
  }
  int sums[2] = {0, 0};
  int num_parsed_buckets = 0;
  for (int i = 0; i < (n >> 1); i++) {
    while (buckets[num_parsed_buckets] == 0) num_parsed_buckets++;
    buckets[num_parsed_buckets]--;
    sums[0] += num_parsed_buckets;
  }
  for (int i = (n >> 1); i < n; i++) {
    while (buckets[num_parsed_buckets] == 0) num_parsed_buckets++;
    buckets[num_parsed_buckets]--;
    sums[1] += num_parsed_buckets;
  }
  LL result = 1ll * sums[1] * sums[1] + 1ll * sums[0] * sums[0];
  cout << result << "\n";
}
int main()
{
  lcl ios_base::sync_with_stdio(0);cin.tie(0);
  int t = 1;
//   cin >> t;
  while (t--) solve();
  return 0;
}
