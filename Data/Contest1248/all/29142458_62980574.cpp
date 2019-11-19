#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+20;
int n,m;
int main() {
  int _;cin >> _;
  while(_--){
    cin >> n;
    ll odd=0,even=0;
    for (int i = 0; i < n; ++i) {
      int cur;
      cin >> cur;
      if(cur&1)odd++;
      else even++;
    }
    ll odd2=0,even2=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int cur;
      cin >> cur;
      if(cur&1)odd2++;
      else even2++;
    }
    cout << odd2*odd + even*even2 << endl;
  }


}