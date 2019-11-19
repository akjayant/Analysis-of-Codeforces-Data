#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll t,n,i,j,k,l;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    k=sqrt(n);
    ll ans=n;
    for (i=2;i<=k;i++)
    {
        if (n%i==0){
            ans=__gcd(ans,i);
            ans=__gcd(ans,n/i);
        }
    }
    cout<<ans<<'\n';
    return 0;
}