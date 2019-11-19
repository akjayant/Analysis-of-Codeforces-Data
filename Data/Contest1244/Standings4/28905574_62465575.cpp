#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a+c-1)/c, y = (b+d-1)/d;
    if(x+y > k) cout << -1 << endl;
    else cout << x << " " << y << endl;
  }
}
