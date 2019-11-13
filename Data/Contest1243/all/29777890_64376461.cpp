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
int T;
int n,a[maxn],t[maxn];
itn ans;
void update(int x)
{
    for(;x;x-=(x&-x)) t[x] ++;
}
int get(int x)
{
    int res = 0;
    for(;x<=1005;x+=(x&-x)) res += t[x];
    return res;
}
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
        ans = 0;
        cin >> n;
        reset(t);
        for(int i=1; i<=n; i++)
        {
            cin >> a[i];
            update(a[i]);
        }
        for(int i=1; i<=1000; i++)
        {
            if(i <= get(i)) ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}
