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


int n, m, t, arr[MAXN], good, bad;
bool feasible = true;
string s;

void met() {
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    m = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        m = max(m, max(2*(i+1), 2*(n-i)));
      }
    }
    cout << m << endl;
  }
  
}
