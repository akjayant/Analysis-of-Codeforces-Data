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
   int n;
   cin >> n;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   sort(all(a));
   int l=0,h=n-1;
   int x =0,y = 0;
   while(l<=h){
      if(l==h){
         x += a[h];
         break;
      }
      x += a[h];
      y += a[l];
      h--;
      l++;
   }
   int ans = x*x+y*y;
   cout << ans << '\n';
   return 0;
}