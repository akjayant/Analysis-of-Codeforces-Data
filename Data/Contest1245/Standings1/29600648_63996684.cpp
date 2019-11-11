#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    if(__gcd(a,b) == 1) cout << "Finite" << endl;
    else cout << "Infinite" << endl;
  }
}
