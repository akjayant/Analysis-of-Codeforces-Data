#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

ll gcd(ll a, ll b) {
  if(a < b) gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  int a[t],b[t];
  rep(i,t){
    cin >> a[i] >> b[i];    
  }
  rep(i,t){
    if(gcd(a[i],b[i])==1){
      cout << "Finite" <<endl;      
    }
    else {
      cout << "Infinite"  << endl;
    }
  }

  
  return 0;
    

}
