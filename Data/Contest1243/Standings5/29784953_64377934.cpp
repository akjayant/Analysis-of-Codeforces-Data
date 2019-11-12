///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "main"
#define maxn 100005
#define MOD 1000000007
#define pii pair<int, int>
int t,n,a[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int res=0;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<=n; ++i)
          {
              int dem=0;
              for(int j=1; j<=n; ++j)
          {
              if(a[j] >=i) ++dem;
          }
          if(dem >= i)
             res=max(res,i);
          }
          cout<<res<<"\n";
    }
}
