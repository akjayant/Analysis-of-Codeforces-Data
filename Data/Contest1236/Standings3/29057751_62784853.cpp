#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;

const int MAX=100000009;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t,a,b,c,ta,tb,tc;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        ta=a,tb=b,tc=c;
        int ans1=0,ans2=0;
        while(ta>0&& tb>1)
        {
            ans1+=3;
            ta--;
            tb-=2;
        }
        while(tb>0&& tc>1)
        {
            ans1+=3;
            tb--;
            tc-=2;
        }
        ta=a;
        tb=b;
        tc=c;
        while(tb>0&& tc>1)
        {
            ans2+=3;
            tb--;
            tc-=2;
        }
        while(ta>0&& tb>1)
        {
            ans2+=3;
            ta--;
            tb-=2;
        }
        cout<<max(ans1,ans2)<<'\n';
    }
}
