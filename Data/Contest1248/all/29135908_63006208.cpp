#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   int nn = max(n,m);
   vector<int> a(nn+1,0);
   a[0] = 0;
   a[1] = 1;
   a[2] = 2;
   f(i,3,nn+1){
      a[i] = a[i-1]+a[i-2];
      a[i] = a[i]%MOD;
   }
   int ans = ((a[m]+a[n]-1)*2)%MOD;
   cout << ans << '\n';
   return 0;
} 