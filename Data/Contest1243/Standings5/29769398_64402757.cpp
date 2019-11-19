#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, a1 ;
  cin >> a;
  a1 = a;
  vector<long long> vec;
  for(int x =2; x<=sqrt(a); x++){
    int i =0;
    while(a1 % x == 0){
      i++;
      a1 /= x;
    }

    if(i > 0 ){
      vec.push_back(x);
    }
  }
  if(a1 != 1)vec.push_back(a1);
  if(vec.size() == 0)cout << a;
  else if(vec.size() == 1)cout << vec[0];
  else cout << 1;
  return 0;
}
