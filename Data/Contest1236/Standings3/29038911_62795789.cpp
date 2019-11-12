#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
#define plll pair<pll,pll>
#define xx first.first
#define yy first.second
#define zz second.first
#define br second.second
#define INF 1000000000
using namespace std;


ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}

int a[305][305];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    int tre=n*n;
    for(int j=1;j<=n;j++)
    {
        if(j<=n/2)
        {
            for(int i=1;i<=n;i++)
            {
                a[i][j]=tre;
                tre--;
            }
        }
        else
        {
            for(int i=n;i>0;i--)
            {
                a[i][j]=tre;
                tre--;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
