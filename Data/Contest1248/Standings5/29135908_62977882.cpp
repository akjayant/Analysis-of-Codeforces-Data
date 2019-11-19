#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n;
   cin >> n;
   vector<int> p(n);
   int ev = 0, od = 0;
   f(i,0,n){
      cin >> p[i];
      if(p[i] & 1) od++;
      else ev++;
   }
   int m;
   cin >> m;
   vector<int> q(m);
   int ev1=0,od1=0;
   f(i,0,m){
      cin >> q[i];
      if(q[i] & 1) od1++;
      else ev1++;
   }
   int ans = ev1*ev+od*od1;
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
