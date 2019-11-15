#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <assert.h>
#include <chrono>
#include <random>
#include <functional>
#include <bitset>
#include <iterator>

using namespace std;

using ll = long long;

const int MOD = (int)(1e9 + 7);
const double PI = 3.14159265358979323846;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int A[3];
    for (int i = 0; i < 3; i++)
      cin >> A[i];
    string S;
    cin >> S;
    string ans(n, '\0');
    map<int, vector<int> > freq;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == 'R') freq[0].push_back(i);
      if (S[i] == 'P') freq[1].push_back(i);
      if (S[i] == 'S') freq[2].push_back(i);
    }
    int take = 0;
    int a = A[0];
    int b = A[1];
    int c = A[2];
    for (int i = 0; i < min( (int)freq[0].size(), b); i++)
      ans[freq[0][i]] = 'P', A[1]--, take++;
    for (int i = 0; i < min( (int)freq[1].size(), c); i++)
      ans[freq[1][i]] = 'S', A[2]--, take++;
    for (int i = 0; i < min( (int)freq[2].size(), a); i++)
      ans[freq[2][i]] = 'R', A[0]--, take++;
    for (int i = 0; i < n; i++) {
      if (ans[i] == '\0') {
	for (int j = 0; j < 3; j++) {
	  if (A[j] > 0) {
	    A[j]--;
	    if (j == 0) ans[i] =  'R';
	    if (j == 1) ans[i] = 'P';
	    if (j == 2) ans[i] = 'S';
	    break;
	  }
	}
      }
    }
    if (take >= (n + 1) / 2) {
      cout << "YES\n";
      cout << ans << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
