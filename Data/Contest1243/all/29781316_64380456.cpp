#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1006;
ll n, m, i, j, k, a, b, ans, v[N], q;
int main()
{
    cin>>q;
    while(q)
    {
        --q;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>v[i];
        sort(v+1,v+n+1);
        ans=-1;
        for(i=1;i<=n;i++)
        {
            ans=max(ans,min(n-i+1,v[i]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
