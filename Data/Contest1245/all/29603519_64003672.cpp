#include<bits/stdc++.h>

#define file ""
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///freopen(file".inp","r",stdin);
    ///freopen(file".out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d[4];
        cin >> n >> d[1] >> d[2] >> d[3];
        string s, ans="";
        cin >> s;
        f0 (i, n) ans += " ";
        f0 (i, n)
        {
            if (s[i]=='R'&&d[2]) ans[i]='P', d[2]--;
            if (s[i]=='P'&&d[3]) ans[i]='S', d[3]--;
            if (s[i]=='S'&&d[1]) ans[i]='R', d[1]--;
        }
        if (d[1]+d[2]+d[3] > n/2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        f0 (i, n) if (ans[i]==' ')
        {
            //cout << i << ' ';
            if (d[1]) ans[i]='R', d[1]--;
            else
                if (d[2]) ans[i]='P', d[2]--;
            else
                if (d[3]) ans[i]='S', d[3]--;
        }
        cout << ans; el;
    }
    return 0;
}
