#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
ll a[maxn];
int main()
{
    int n;
    ll s=0, sum=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n/2; i++)
        s+=a[i];
    ll ans=0;
    ans=s*s+(sum-s)*(sum-s);
    cout<<ans<<endl;
    return 0;
}
