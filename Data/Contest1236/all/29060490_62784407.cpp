#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define sp fixed<<setprecision
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define bp __builtin_popcount
#define int ll
using namespace std;
ll M = (1e9)+7;

signed main()
{
    FAST
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        int a,b,c,ans=0;
        cin>>a>>b>>c;
        int d=(c/2);
        d=min(d,b);
        ans+=3*d;
        b-=d;
        d=(b/2);
        d=min(d,a);
        ans+=3*d;
        a-=d;
        cout<<ans<<endl;
    }
    return 0;
}

/*

*/
