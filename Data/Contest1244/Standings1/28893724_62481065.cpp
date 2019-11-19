#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int n,p,d,w;

int32_t main()
{
    IOS
    cin>>n>>p>>w>>d;
    for (int i=0;i<=10000000;i++)
    {
        if (p-i*d>=0&&(p-i*d)%w==0&&i+(p-i*d)/w<=n)
        {
            cout<<(p-i*d)/w<<' '<<i<<' '<<n-i-(p-i*d)/w<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}

