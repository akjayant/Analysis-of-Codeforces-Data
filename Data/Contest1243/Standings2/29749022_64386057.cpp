/*
    Mbak Rose Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,j,k,x,y,ans,m,q,curr,temp;
    int tc;
    ll now;
    scanf("%lld",&now);
    ll akar = sqrt(now);
    ll i;
    ll rose = -1;
    ll jisoo = 1;
    ll skrg = now;
    ll gcd = 0;
    for(i=2;i<=akar;i++)
    {
        if(now % i == 0)
        {
            gcd = __gcd(gcd, i);
            gcd = __gcd(gcd, now/i);
            rose = 1;
        }
    }
    if(rose == -1)
    {
        printf("%lld\n", now);
    }
    else
    {
        printf("%lld\n", gcd);
    }
    return 0;
}
