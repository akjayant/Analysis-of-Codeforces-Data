#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,a,b,c,d,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        x=(a+c-1)/c;
        y=(b+d-1)/d;
        if(x+y<=k)
        {
            cout<<x<<" "<<y<<"\n";
        }
        else
            cout<<-1<<"\n";
    }



}
