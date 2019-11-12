using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second

signed main()
{
    IOS;
    int t; cin>>t; while(t--)
    {
        int a,b,c; cin>>a>>b>>c;
        int ans=0;
        int f = min(b,c/2);
        b-=f;
        c-=f*2;
        ans+=f;
        f = min(a,b/2);
        ans+=f;
        cout<<ans*3<<endl;
    }
}
