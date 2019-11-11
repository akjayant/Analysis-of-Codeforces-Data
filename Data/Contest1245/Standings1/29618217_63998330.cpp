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


int a, b, arr[MAXN];

void met() {
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
      arr[i] = 0;
    }
    for (int i = 0; arr[i] == 0; i=(i+a)%b) {
      arr[i] = 1;
    }
    int feasible=1;
    for (int i = 0; i < b; i++) {
      feasible&=arr[i];
    }
    cout << (feasible? "Finite" : "Infinite") << endl;
  }
  
}
