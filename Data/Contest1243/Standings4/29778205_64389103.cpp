#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
ll n,res;
void solve()
{
    cin>>n;
    res=n;
    ll i=2;
    while(i<=sqrt(n))
    {
        if(n%i==0)
        {
            res=__gcd(res,i);
            res=__gcd(res,n/i);
        }
        i++;
    }
    cout<<res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("contests599.inp","r",stdin);
    //freopen(".out","w",stdout);
    solve();



}
