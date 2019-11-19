#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll r=sqrt(n);
    ll gccd=n;
    ll a,b;
    for ( int i=2;i<=r;i++)
    {
        if (n%i==0)
        {
            a=i;
            b=n/i;
            gccd=__gcd(gccd,a);
            gccd=__gcd(gccd,b);
        }
    }
    cout<<gccd<<endl;
    return 0;
}
