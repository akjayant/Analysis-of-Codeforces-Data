#include <bits/stdc++.h>
#define ls rt*2
#define rs rt*2+1
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll z=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            if(z)
                z=__gcd(i,z);
            else
                z=i;
        }
    }
    if(z==0)
        z=n;
    else if(n>1)
    z=__gcd(n,z);
    cout<<z<<endl;
}
