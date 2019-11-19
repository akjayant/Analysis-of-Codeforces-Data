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
  string s;
  cin >> s;

  int left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') left++;
    else right++;
  }

  if (left != right) {
    cout << 0 << endl; // impossible
    cout << 1 << " " << 1 << endl; // any position
    return 0;
  }

  vector<char> sv(n);
  vector<int> depth(n);
  int bestl = 0, bestr = 0, bestCount = 0;
  for (int i = 0; i < n; i++) sv[i] = s[i];
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(sv[i], sv[j]);
      depth[0] = ((sv[0] == '(') ? 1 : -1);
      for (int k = 1; k < n; k++) {
        depth[k] = depth[k-1] + ((sv[k] == '(') ? 1 : -1);
      }
      int minDepth = depth[0], count = 1;
      for (int k = 1; k < n; k++) {
        if (depth[k] == minDepth) count++;
        else if (depth[k] < minDepth) {
          minDepth = depth[k];
          count = 1;
        }
      }
      if (count > bestCount) {
        bestl = i;
        bestr = j;
        bestCount = count;
      }
      swap(sv[i], sv[j]);
    }
  }

  cout << bestCount << endl;
  cout << (bestl + 1) << " " << (bestr + 1) << endl;

  return 0;
}
