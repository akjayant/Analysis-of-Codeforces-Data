#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,a,b,c,xd,res;
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>a>>b>>c;
        xd=min(b,c/2);
        res+=xd*3;
        b-=xd;
        xd=min(a,b/2);
        res+=xd*3;
        cout<<res<<"\n";
    }
}
