#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
ll a[100003];
ll ans,k;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    k=0;
    for(int i=1;i<=n/2;i++)
    {
        k+=a[i];
    }
    ans+=k*k;
    k=0;
    for(int i=n/2+1;i<=n;i++)
    {
        k+=a[i];
    }
    ans+=k*k;
    cout<<ans;
    return 0;
}
