#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(v) (v).begin(),v.end()
#define rall(v) (v).rbegin(),v.rend()
#define sz(v) (int)(v).size()
#define ch(c) (c - 'a')

typedef long long ll;
typedef pair<int, int> pi;

const int N = 112345;
int arr[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif
  int n;
  ll k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);
  int i = 0, j = n - 1;
  int st = arr[0], en = arr[n - 1];
  if (n == 2) {
    int d = en - st;
    cout << max(0LL, d - k) << endl;
    return 0;
  }
  i++, j--;
  ll f1 = 1, f2 = 1;
  bool ok = true;
  while (ok) {
    ok = false;
    ll d = arr[i] - st;
    if (d * f1 <= k) {
      st += d, k -= f1 * d;
      ok = true;
      f1++;
    } else {
      ll rem = k / f1;
      if (rem) {
        st += rem;
        k -= rem * f1;
      }
    }
    if (i > j)
      break;
    d = en - arr[j];
    if (d * f2 <= k) {
      en -= d, k -= f2 * d;
      ok = true;
      f2++;
    } else {
      ll rem = k / f2;
      if (rem) {
        en -= rem;
        k -= rem * f2;
      }
    }
//    cout << st << " " << en << endl;
    i++, j--;
  }
  cout << en - st << endl;
  return 0;
}
