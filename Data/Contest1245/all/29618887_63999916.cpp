#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b; cin >> a >> b;
  int g = __gcd(a, b);
  if(g == 1) {
    cout << "Finite\n";
  } else {
    cout << "Infinite\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}