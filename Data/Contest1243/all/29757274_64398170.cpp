#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
  long long n;
  cin >> n;
  long long ans = n;
  int cn = 0;
  int fl = 0;
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0) {
      fl = 1;
      break;
    }
  }
  if(!fl) {
    cout << n << endl;
    return 0;
  }
  int f;
  for(int i = 2; i <= 1e7; i++){
    if(n % i == 0) {
      cn ++;
      f = i;
      while(n % i == 0) {
        n /= i;
      }
    }
  }  
  if(n != 1)cn ++;
  if(cn == 1) {
    cout << f;
  }
  else {
    cout << 1;
  }
	return 0;
}