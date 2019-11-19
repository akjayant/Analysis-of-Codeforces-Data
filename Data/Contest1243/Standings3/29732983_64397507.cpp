#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    scanf("%lld",&n);
    x=n;
    m=sqrt(n);
    for(i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            a=n/i;
            x=__gcd(x,i);
            x=__gcd(x,a);
        }
    }
    cout<<x<<endl;
}
