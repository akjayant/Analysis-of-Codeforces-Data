#include <bits/stdc++.h>
   #define f first
    #define s second
    #define int long long
    #define ll long long
    using namespace std;

  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t ;
    cin >> t;
    for ( int o = 1 ; o <= t ; o++)
    {
ll a,b,c;
cin >> a >> b >> c;
ll ans = 0;
ans+=min(b,c/2);
b-=ans;
cout << 3*(ans + min(a,b/2)) << endl;

    }
 }
