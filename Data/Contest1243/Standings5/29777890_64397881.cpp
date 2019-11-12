// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define task ""
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)
#define itn int
using namespace std;
itn T;
string s,t;
vector<pii> ans;
int d[maxn];
itn n;
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> T;
    while(T--)
    {
        ans.clear();
        reset(d);
        cin >> n >> s >> t;
        s = " " + s;
        t = " " + t;
        for(int i=1; i<=n; i++)
        {
            d[s[i] - 'a'] ++;
            d[t[i] - 'a'] ++;
        }
        bool ok = 1;
        for(auto v : d)
        {
            if(v & 1)
                ok = 0;
        }
        if(!ok)
        {
            cout << "NO \n";
            continue;
        }
        cout << "YES \n";
        for(int i=1; i<=n; i++)
        {
            if(s[i] == t[i])
                continue;
            int f = t.rfind(t[i]);
            if(f > i)
            {
                ans.emplace_back(i,f);
                swap(s[i],t[f]);
                continue;
            }
            f = s.rfind(s[i]);
            if(f > i)
            {
                ans.emplace_back(f,i);
                swap(s[f],t[i]);
                continue;
            }
            f = s.rfind(t[i]);
            if(f > i)
            {
                ans.emplace_back(f,f);
                ans.emplace_back(i,f);
                swap(s[f],t[f]);
                swap(s[i],t[f]);
                continue;
            }
            f = t.rfind(s[i]);
            if(f > i)
            {
                ans.emplace_back(f,f);
                ans.emplace_back(f,i);
                swap(s[f],t[f]);
                swap(t[i],s[f]);
                continue;
            }
        }
        cout << ans.size() << '\n';
        for(auto v : ans)
            cout << v.F << " " << v.S << '\n';
    }
    return 0;
}
