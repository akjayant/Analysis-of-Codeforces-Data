#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    if(p==0)
    {
        cout<<"0 0 "<<n<<'\n';
        return 0;
    }
    if(p<d)
    {
        cout<<"-1"<<'\n';
        return 0;
    }
    if(n*w<p)
    {
        cout<<"-1"<<'\n';
        return 0;
    }
    if(p%__gcd(w,d))
    {
        cout<<"-1"<<'\n';
        return 0;
    }
    ll ansd=-1,answ=-1;
    for(ll i=0;i<w/__gcd(w,d);i++)
    {
        if((i*d)%w==p%w)
        {
            ansd=i;
            answ=(p-i*d)/w;
            break;
        }
    }
    if(ansd+answ>n)
    {
        cout<<"-1"<<'\n';
        return 0;
    }
    cout<<answ<<' '<<ansd<<' '<<n-answ-ansd<<'\n';
}
