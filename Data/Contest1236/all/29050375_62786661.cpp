#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define nl cout<<endl
#define MOD 1000000007
#define loop(i,start,end) for(ll i=start;i<end;i++)
#define N 100001
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
ull expo(ull base,ull x)
{
    ull res = 1;    
    base = base % MOD; 
    while (x > 0)
    {
        if (x & 1)
            res = (res*base) % MOD;
        x= x>>1;
        base = (base*base) % MOD;  
    }
    return res;
}
int main() 
{
    fastio();
    #ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    cout<<expo(expo(2,m)-1,n);

  return 0;
}