#include <bits/stdc++.h>
using namespace std;

long long n,d,o;

int main() {
  cin >> n;
  o = n;
  if(n == 1) {
    cout << 1;
    return 0;
  }
  for(long long i = 2; i <= sqrt(n); i++) {
    while(n % i == 0) {
      n /= i;
      if(!d) {
        d = i;
      } else if(d != i) {
        cout << "1\n"; 
        return 0;
      }
    }
  }
  if(n > 1) {
    if(!d) {
      d = n;
    } else {
      cout << "1\n";
      return 0;
    }
  }
  cout << d;
  return 0;
}