#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
        lli a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        lli ans1=0,ans2=0;
        ans1=a/c;
        if(a%c!=0) ans1++;
        ans2=b/d;
        if(b%d!=0) ans2++;
        if(ans1+ans2<=k)
        {
            cout<<ans1<<" "<<ans2<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}