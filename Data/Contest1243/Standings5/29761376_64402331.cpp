#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

set< ll > prime_factor(ll n) {
  set<ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    if(n%i==0) ret.insert(i);
    while(n % i == 0) {
      n /= i;
    }
  }
  if(n != 1) ret.insert(n);
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  auto st=prime_factor(n);
  if(st.size()==1) cout << *st.begin() << endl;
  else cout << 1 << endl;
  
  return 0;
    

}
