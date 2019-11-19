#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a,b,c,d,k;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        ll p1,p2;
        if(a%c!=0)p1=a/c+1;
        else p1=a/c;
        if(b%d!=0)p2=b/d+1;
        else p2=b/d;
        if(p1+p2<=k)cout<<p1<<" "<<p2<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}