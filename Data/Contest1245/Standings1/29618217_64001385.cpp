#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9+9;
const int MAXN = 1000006;


int n, m, k, a, b, c; char arr[MAXN];
char cc;

void met() {
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> k;
  while (k--) {
    cin >> n;
    cin >> a >> b >> c;
    m=0;
    for (int i = 0; i < n; i++) {
      cin >> cc;
      arr[i] = -1;
      if (cc == 'R' && b > 0) {
        b--;
        arr[i] = 'P';
        m++;
      } else if (cc == 'P' && c > 0) {
        c--;
        arr[i] = 'S';
        m++;
      } else if (cc == 'S' && a > 0) {
        a--;
        arr[i] = 'R';
        m++;
      }
    }
    if (m >= (n+1)/2) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        if (arr[i] != -1) cout << arr[i];
        else if (a > 0) {
          a--;
          cout << 'R';
        } else if (b > 0) {
          b--;
          cout << 'P';
        } else {
          c--;
          cout << 'S';
        }
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
}
