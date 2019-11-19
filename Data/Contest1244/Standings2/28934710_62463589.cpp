#include <bits/stdc++.h>
#define DIM 100007
#define INF 1000000007
using namespace std;
long long t,a,b,c,d,k;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        long long x = a/c + (a%c!=0);
        long long y = b/d + (b%d!=0);
        if(x+y>k) cout<<-1<<endl;
        else cout<<x<<' '<<y<<endl;

    }

    return 0;
}
