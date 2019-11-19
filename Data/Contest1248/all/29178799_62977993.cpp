#include <bits/stdc++.h>

using namespace std;
long long t,n,p[100100],q[100100],m,par,imp,ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        par=0;
        imp=0;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            if(p[i]%2==0) par++;
            else imp++;
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>q[i];
            if(q[i]%2==0) ans+=par;
            else ans+=imp;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
