#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>

using namespace std;

#define int long long
#define forn for (int i=0; i<n; i++)
#define form for (int i=0; i<m; i++)
#define fornj for (int j=0; j<n; j++)
#define formj for (int j=0; j<m; j++)
#define edge l[i]--; r[i]--; d[l[i]].push_back(r[i]); d[r[i]].push_back(l[i]);

void write(const vector<int> &a)
{
    for (auto i:a)
    {
        cout<<i<<" ";
    }
}

int a[1000000+5];

int b[1000000+5];

int c[1000000+5];

int32_t main()
{
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            b[i]=0;
            c[i]=0;
        }
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        c[n]=b[n];
        for (int i=n-1; i>=0; i--)
        {
            c[i]=c[i+1]+b[i];
        }
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            if (c[i]>=i) ans=i;
        }
        cout<<ans<<'\n';
    }
}
