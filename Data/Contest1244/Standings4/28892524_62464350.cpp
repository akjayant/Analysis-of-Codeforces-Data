#include<bits/stdc++.h>
#define int long long


using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>> t;
    while (t--)
    {
        long double a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;

        long double x,y;
        x=ceil(a/c);
        y=ceil(b/d);
        if(x+y<=k)
        {
            cout<<x<<" "<<y<<"\n";
        } else
            cout<<-1<<"\n";
    }
}