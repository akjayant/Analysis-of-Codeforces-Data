#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define plll pair<pll,pll>
using namespace std;


/*ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t>0)
    {
        int a,b;
        cin>>a>>b;

        int nzd=__gcd(a,b);
        if(nzd==1)
        {
            cout<<"Finite\n";
        }
        else
        {
            cout<<"Infinite\n";
        }
        t--;
    }


    return 0;
}
