#include <bits/stdc++.h>
using namespace std;

using ll = long long;



int main() {
	int t;
  cin >>t;
  for(int i = 0; i < t; i++){
    bool asd = true;
    int a,b;
    cin >>a >>b;

    if(a<b){
      int sw = a;
      a = b;
      b = sw;
    }

    for(int i = 2;i <= a; i++){
      bool f = (a%i==0);
      
      
      for(int j = 2; (j < i && f); j++){
        if(i%j==0)f = false;
      }
      if(f && b%i==0){
        cout <<"infinite\n";
        asd = false;
        break;
      }
    }
    if(asd)
    cout << "finite\n";
    continue;
  }
}
