//
#include<iostream>
using namespace std;
#define ll long long
int T;
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    cin>>T;
    ll n,m;
    while(T--)
    {
        cin>>n>>m;
        puts((gcd(n,m)!=1)?"Infinite":"Finite");
    }
}
