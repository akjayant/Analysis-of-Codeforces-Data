#include <bits/stdc++.h>
using namespace std;


long long t,n,a,sl[3][3];
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("fuck.inp","r",stdin);
    //freopen("fuck.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;memset(sl,0,sizeof(sl));
        for (int i=1;i<=n;++i) {cin>>a;sl[0][a%2]++;}
        cin>>n;
        for (int i=1;i<=n;++i) {cin>>a;sl[1][a%2]++;}
        cout<<sl[0][0]*sl[1][0]+sl[0][1]*sl[1][1]<<'\n';
    }
}
