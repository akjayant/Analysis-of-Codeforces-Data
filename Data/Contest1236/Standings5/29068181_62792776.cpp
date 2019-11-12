/* 
 * Author: Imagine_I
 * Time: 2019-10-17 21:42:21
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll num1=qpow(2,m)-1;
    ll ans=qpow(num1,n);
    cout<<ans<<'\n';
	return 0;
}
