//g++  5.4.0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
ll po(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return po((x*x)%M,n/2);
    else
        return (x*po((x*x)%M,(n-1)/2))%M;

}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll d=(po(2,m)-1+M)%M;
    d=po(d,n);
    cout<<d;
}