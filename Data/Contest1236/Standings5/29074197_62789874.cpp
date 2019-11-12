#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<time.h>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll fpow(ll a,ll n)
{
    ll sum=1,base=a%mod;
    while(n!=0)
    {
        if(n&1)sum=sum*base%mod;
        base=base*base%mod;
        n/=2;
    }
    return sum;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<fpow((fpow(2,m)-1+mod)%mod,n)<<endl;
    return 0;
}
