#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double lf;

const int N = 1e5+2;
const ll oo = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #else
    #define endl '\n'
  #endif
  
  int t; cin >> t;
  while(t--) {
    int a, b; cin >> a >> b;
    if(__gcd(a, b) == 1)  cout << "Finite" << endl;
    else cout << "Infinite" << endl;
  }
  
}