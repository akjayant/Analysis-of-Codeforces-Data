#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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

unordered_map<int, int> mp[1000000+5];

set<int> used;

int n,m;

void dfs(int v)
{
    auto it=used.begin();
    while (used.size()>0&&it!=used.end())
    {
        int i=(*it);
        if (mp[v].count(i)!=0)
        {
            it++;
            continue;
        }
        if (used.find(i)==used.end())
        {
            it++;
            continue;
        }
        used.erase(i);
        dfs(i);
        if (used.size()>0) it=used.begin();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        mp[l][r]++;
        mp[r][l]++;
    }
    for (int i=0; i<n; i++)
    {
        used.insert(i);
    }
    int ans=0;
    int cur=0;
    while (used.size()>0)
    {
        if (used.find(cur)!=used.end())
        {
            used.erase(cur);
            dfs(cur);
            ans++;
        }
        cur++;
    }
    cout<<ans-1;
}
