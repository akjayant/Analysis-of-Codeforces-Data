#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
const int maxn = 3e5+35;
int a,b,c,d,k,t;
int main(){
  cin >> t;
  while(t--){
  cin >> a >> b >> c >> d >> k;
  bool flag = false;
  for(int x = 0;x <= k; ++x){
    int y = k-x;
    if(c*x >= a && y*d >= b){
      cout << x << " " << y << endl;
      flag = true; break;
    }
  }
  if(!flag) puts("-1");
}
return 0;
}