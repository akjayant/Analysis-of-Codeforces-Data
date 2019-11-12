#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int t1=n*n,t2=1;
    if (n&1)
    {
        t1=n*(n-1),t2=1;
        for (int i=1;i<=n;i++)
        {
        for (int j=1;j<=n/2;j++)
        {
            cout<<t1<<" ";
            t1--;
        }
        for (int j=n/2+1;j<n;j++)
        {
            cout<<t2<<" ";
            t2++;
        }
            cout<<n*n-i+1<<endl;
        }
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n/2;j++)
        {
            cout<<t1<<" ";
            t1--;
        }
        for (int j=n/2+1;j<=n;j++)
        {
            cout<<t2<<" ";
            t2++;
        }
        cout<<endl;
    }
    return 0;
}
