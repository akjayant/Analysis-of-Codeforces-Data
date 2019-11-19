#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    while(cin>>n)
    {
        //memset(col,0,sizeof col);
        ll sq=sqrt(n);
        //vector<ll> divisor;
        ll gcd=n;
        for(ll i=2;i<=sq;i++)
        {
            if(n%i==0)
            {
                gcd=__gcd(gcd,i);
                ll x=n/i;
                gcd=__gcd(gcd,x);
            }
        }
        //sort(divisor.begin(),divisor.end());
        cout<<gcd<<endl;

    }
    return 0;
}
