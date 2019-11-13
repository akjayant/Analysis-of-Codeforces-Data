#include<bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin>>t;

  while(t--) {

    int a,b;
    cin>>a>>b;

    if(a > b)
      swap(a,b);

    int cnt=__gcd(a,b);

    if(cnt != 1)
      cout<<"Infinite\n";
    else
      cout<<"Finite\n";
  }


  return 0;
}