#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;

  sort(a.begin(), a.end());

  int left = 0;
  int right = n-1;
  ll ans1x = 0, ans1y = 0, ans2x = 0, ans2y = 0;
  while (left < right) {
    ans1x += a[left];
    ans1y += a[right];
    ans2x += a[right];
    ans2y += a[left];
    left++;
    right--;
  }
  if (left == right) {
    ans1x += a[left];
    ans2x += a[left];
  }

  ll ans = max((ans1x * ans1x) + (ans1y * ans1y), (ans2x * ans2x) + (ans2y * ans2y));

  cout << ans << endl;

  return 0;
}
