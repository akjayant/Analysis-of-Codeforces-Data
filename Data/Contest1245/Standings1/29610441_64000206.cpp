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
//#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int t,n;
string s;
int a,b,c,aa=0,bb=0,cc=0;
vector<int> v[4]; //R,P,S
char ans[109];

int32_t main()
{
    IOS
    cin>>t;
    while (t--)
    {
        v[0].clear(),v[1].clear(),v[2].clear();
        cin>>n>>a>>b>>c>>s;
        aa=0,bb=0,cc=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='R') v[0].pb(i);
            else if (s[i]=='P') v[1].pb(i);
            else v[2].pb(i);
        }
        memset(ans,0,sizeof(ans));
        if (min(sz(v[2]),a)+min(sz(v[0]),b)+min(sz(v[1]),c)>=(n+1)/2)
        {
            cout<<"YES"<<endl;
            for (int i=0;i<min(sz(v[2]),a);i++) ans[v[2][i]]='R',aa++;
            for (int i=0;i<min(sz(v[0]),b);i++) ans[v[0][i]]='P',bb++;
            for (int i=0;i<min(sz(v[1]),c);i++) ans[v[1][i]]='S',cc++;
            for (int i=0;i<n;i++)
            {
                if (ans[i]!=0) ;
                else if (aa<a) ans[i]='R',aa++;
                else if (bb<b) ans[i]='P',bb++;
                else ans[i]='S',cc++;
            }
            for (int i=0;i<n;i++) cout<<ans[i];
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

