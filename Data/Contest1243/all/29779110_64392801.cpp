#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const ll inf=1e18;
/*ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res;
}*/
ll arr[1000001]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j,f=0,a,b=1,c;
    vector<ll>v;
    for(i=2;i<=1e6;i++)
    {
        if(arr[i]==0)
        {
            v.pb(i);
            for(j=i;j*i<=1e6;j++)
            {
                arr[i*j]=1;
            }
        }
    }
    cin>>n;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout<<n<<endl;
        return 0;
    }
    for(i=0;i<v.size();i++)
    {
        if(n%v[i]==0)
        {
            a=n;
            while(a>1 && a%v[i]==0)
                a=a/v[i];
            if(a==1)
            {
                b=v[i];
                break;
            }
            break;
        }
    }
    cout<<b<<endl;
}
