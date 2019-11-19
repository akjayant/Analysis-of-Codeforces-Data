#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
const int N = 1 << 20;
int main() {
#ifdef local
  freopen("in.txt", "r", stdin);
#endif // local
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _; cin >> _;
  while(_--) {
    int n; cin >> n;
    string s; cin >> s;
    int ans = n;
    for(int i = 0; i < n; i++){
      if(s[i] == '1') {
        ans = max(ans, (i + 1) * 2);
        ans = max(ans, (n - i) * 2);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
