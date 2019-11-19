#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); 
  int t;
  cin >> t;
  for(int i=0;i<t;i++){
    ll n,m,p,q,no=0,ne=0,mo=0,me=0;
    cin >> n;
    for(int j=0;j<n;j++){
      cin >> p; 
      if(p%2==0)ne++;
      else{no++;}
    }
    cin >> m;
    for(int j=0;j<m;j++){
      cin >> q;
      if(q%2==0)me++;
      else{mo++;}
    }
    cout << ne*me+no*mo << "\n";
  }
}