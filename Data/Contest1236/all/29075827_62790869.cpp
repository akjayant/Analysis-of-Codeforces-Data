#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define p 1000000007LL

ll bigmod(ll x,ll n)
{
    ll ans=1LL;
    while(n)
    {
        if(n%2) ans=((ans%p)*(x%p))%p;
        n/=2;
        x=((x%p)*(x%p))%p;
    }
    return ans%p;
}
int main()
{
    ll n,m;
    cin >> n >> m;
    ll ans=bigmod(2LL,m);
    ans--;
    ans=bigmod(ans,n) ;
    cout << ans << endl;

}
