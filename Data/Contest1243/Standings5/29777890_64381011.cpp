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
#define pb push_back
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
int res[maxn];
itn cnt,n;
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> T;
    while(T--)
    {
        cnt = 0;
        cin >> n >> s >> t;
        s = " " + s;
        t = " " + t;
        for(int i=1; i<=n; i++) if(s[i] != t[i]) res[++cnt] = i;
        if(!cnt)
        {
            cout << "YES \n";
            continue;
        }
        if(cnt != 2)
        {
            cout << "NO \n";
        }
        else
        {
            char x = s[res[1]];
            char y = s[res[2]];
            char u = t[res[1]];
            char v = t[res[2]];
            if(u == v && x == y)
            {
                cout << "YES \n";
            }
            else cout << "NO \n";
        }
    }
    return 0;
}
