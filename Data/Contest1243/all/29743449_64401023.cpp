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

int32_t main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            if (ans==0) ans=i;
            break;
        }
    }
    if (ans==0)
    {
        cout<<n;
        return 0;
    }
    int k=n;
    while (k>1)
    {
        if (k%ans!=0)
        {
            cout<<1;
            return 0;
        }
        k/=ans;
    }
    cout<<ans;
}

