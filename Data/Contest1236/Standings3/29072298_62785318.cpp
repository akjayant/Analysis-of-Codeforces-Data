#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
  int a,b,c;
    cin >> a >> b >> c;
    
    int ans =0;
    
    int tt = min(b,c/2);
    
    b-=tt;
    ans+=(3*tt);
    
    tt = min(b/2,a);
    
    ans+=(3*tt);
    
    cout << ans << endl;
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
   cin >> t;
    
    while(t--)
        
    solve();
}