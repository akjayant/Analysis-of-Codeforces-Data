#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define gap ' '
#define mod 1000000007
#define INF 1000000000


int main()
{
    ll n;

    cin>>n;

    ll gcd=n;

    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            gcd=__gcd(gcd,i);
            gcd=__gcd(gcd,n/i);
        }
    }

    cout<<gcd;
}
