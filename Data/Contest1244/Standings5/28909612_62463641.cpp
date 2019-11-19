#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define d long double
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define N 200003
#define inf (int)1e18
#define Arena ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod=1e9+7;

signed main()
{
    Arena
       
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a,b,c,d,k,x,y;
        cin>>a>>b>>c>>d>>k;
        x=(a+c-1)/c, y=(b+d-1)/d;
        if(x+y>k)
            cout<<"-1\n";
        else
            cout<<x<<' '<<y<<'\n';
    }   
    
    
    return 0;
}
