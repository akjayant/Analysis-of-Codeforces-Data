#include <deque>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T-- > 0) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    ans += min(c / 2, b);
    b -= ans;
    ans += min(b / 2, a);
    cout << 3 * ans << endl;
  }
  return 0;
}
