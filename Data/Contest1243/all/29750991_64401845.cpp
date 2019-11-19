#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
vector<ll> pf;
void getprime(ll n)
{
    for(ll i=2; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            pf.push_back(i);
            while(n%i==0)
            {
                n/=i;
            }
        }

    }
    if(n!=1)
        pf.push_back(n);
}
int main()
{
    ll n;
    cin>>n;
    if(n==1)
        cout<<1<<endl;
    else
    {
        getprime(n);
        if(pf.size()>1)//素因子个数
            cout<<1<<endl;
        else
            cout<<pf[0]<<endl;
    }
}
