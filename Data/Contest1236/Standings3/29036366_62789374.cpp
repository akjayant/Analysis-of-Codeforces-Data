#include <bits/stdc++.h>
#include <map>
#define ll long long
#define MAXN 100010
#define MAXE 300010
#define MOD 1000000007
using namespace std;
long long ans;
ll ksm(ll a,ll b){
    ll ans = 1;
    ll base = a%MOD;
    while(b){
        if(b & 1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
   //freopen("testdata.in.txt","r",stdin);

      int n,m;
      cin>>n>>m;
      long long bas=ksm(2,m)-1;
      ans=ksm(bas,n);
      cout<<ans%MOD<<endl;



   return 0;
}

