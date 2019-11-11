#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld%lld",&a,&b);
        a=__gcd(a,b);
        if(a==1)
        {
            printf("Finite\n");
        }
        else
        {
            printf("Infinite\n");
        }
    }
}
