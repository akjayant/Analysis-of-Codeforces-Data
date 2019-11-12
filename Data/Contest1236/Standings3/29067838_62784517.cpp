#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int maxn=2e5;
const int mod=1e9+7;
int n;
int main()
{
    //freopen("ce.in","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c;
        int ans=0;
        cin>>a>>b>>c;
        for(int x=0;x<=a;++x)
            for(int y=0;2*y<=c;++y)
                if(2*x+y<=b) ans=max(ans,3*(x+y));
        cout<<ans<<endl;
    }
    return 0;
}
