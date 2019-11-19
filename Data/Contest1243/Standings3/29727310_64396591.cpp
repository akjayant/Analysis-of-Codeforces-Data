#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int f(int n){
  set<int> d;
  for(int i = 2; i <= sqrt(n); i ++){
    while(n % i == 0){
      d.insert(i);
      n /= i;
    }
  }
  if(n != 1)
    d.insert(n);
  if(d.size() > 1)
    return 1;
  return *d.begin();
}

int32_t main(){
  int n; cin >> n;
  if(n == 1)
    cout << 1;
  else
    cout << f(n);
}
