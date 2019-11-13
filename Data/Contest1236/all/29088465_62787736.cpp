#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back

#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    speed
    int tt;cin>>tt;
    while(tt--)
    {
        int a,b,c;cin>>a>>b>>c;
        int ans=0;
        while(b>=1&&c>=2)
        {
            b-=1;c-=2;ans+=3;
        }
        while(a>=1&&b>=2)
        {
            a-=1;b-=2;ans+=3;
        }
        cout<<ans<<"\n";
    }
}