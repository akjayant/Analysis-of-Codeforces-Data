#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

char s[N],t[N];

int f(ll x,ll &t)
{
    int m=sqrt(x+0.5);
    int cnt=0;
    for(int i=2;i<=m;++i)
    {
        if(x%i==0)
        {
            if(cnt==0)
                t=i;
            ++cnt;
            while(x%i==0)x/=i;
        }
    }
    if(x>1)
    {
       if(cnt==0)
        t=x;
       ++cnt;
    }
    return cnt;
}

int main() {
    ll n;
    cin>>n;

    if(n==1)
        puts("1");
    else
    {
        ll t;
        int x=f(n,t);
        if(x>=2)
            cout<<1;
        else
            cout<<t;
    }
    return 0;
}
