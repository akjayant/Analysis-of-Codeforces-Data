#include<bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
const int mod=1e9+7;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define si(a) a.size()
#define pii pair<int,int>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debugging.h"
#endif


int32_t main() {
   std::ios::sync_with_stdio(false);cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      int a,b;
      cin>>a>>b;
      if( __gcd(a,b) ==1)
      {
         cout<<"Finite\n";
      }
      else
      cout<<"Infinite\n";
   }
   return 0;
}