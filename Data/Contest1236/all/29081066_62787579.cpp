#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN=100005;
const int MOD=1000000007;
const int MAMOD=998244353;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    ll a,b,c,ret;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        ret=0;
        for( ll i = 0 ; i <= a ; i ++)
            for( ll j = 0 ; j <= b ; j ++)
                if(i * 2 + j <= b && j * 2 <= c)
                    ret=max(ret , i + i * 2 + j + j * 2);
                cout<<ret<<endl;
    }
    return 0;
}