#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
 
using namespace std;
const ll maxn=510000,inf=1e18,LOG=20,mod=998244353;

#define  int ll


int q, n, ans;
char a[maxn];
main()
{
    cin >> q;
    forn(1 ,te,q)
    {
        cin >> n;
        ans = n;
        forn(1, i, n)
        {
            cin >> a[i];
            if(a[i] == '1')
            {
                ans = max(ans, i * 2);
                ans = max(ans, (n - i + 1) * 2);
            }
        }
        cout << ans << endl;
    }
}