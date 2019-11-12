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
vector<int> v[305];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    int ans=1;
    while(ans<=n*n) {
        for (int i = 1; i <= n; ++i) {
            v[i].push_back(ans);
            ans++;
        }
        if(ans>n*n)
            break;
        for (int i = n; i >=1; --i) {
            v[i].push_back(ans);
            ans++;
        }
    }
    for(int i=1;i<=n;++i)
    {
        int sz=v[i].size();
        for(int j=0;j<sz;++j)
        {
            if(j!=0)
                cout<<" ";
            cout<<v[i][j];
        }
        cout<<"\n";
    }
    return 0;
}