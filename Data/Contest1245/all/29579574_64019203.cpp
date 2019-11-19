#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 3e3 + 1;
int dp[N];
pair<int, int> koord[N];
int price[N];
vector<pair<int, pair<int, int>>> edges;
int snm[N];
int getroot(int v)
{
    if(snm[v] != v)
        return snm[v] = getroot(snm[v]);
    return v;
}
bool merge(int v1, int v2)
{
    v1 = getroot(v1), v2 = getroot(v2);
    if(v1 == v2)
        return 0;
    snm[v1] = v2;
    return 1;
}
int k[N];
signed main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin>>a>>b;
        koord[i] = {a, b};
    }
    for(int i = 0; i < n; i++)
        cin>>price[i];
    for(int i = 0; i < n; i++)
    {
        cin>>k[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            edges.push_back({ (abs(koord[i].first - koord[j].first) + abs(koord[i].second - koord[j].second)) * (k[i] + k[j]),{i, j}});
        }
    }
    for(int i = 0; i < n; i++) {
        edges.push_back({ price[i], {i, n}});
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i <= n; i++)
        snm[i] = i;
    int mi = 0;
    vector<int> stations;
    vector<pair<int, int>> ans;
    for(auto i : edges)
    {
        if(merge(i.second.second, i.second.first))
        {
            mi += i.first;
            if(i.second.first != n && i.second.second != n)
            {
                ans.push_back({i.second.first, i.second.second});
            }
            else
            {
                if(i.second.second != n)
                    stations.push_back(i.second.second);
                else
                    stations.push_back(i.second.first);
            }
        }
    }
    cout<<mi<<endl;
    cout<<stations.size()<<endl;
    for(auto i : stations)
    {
        cout<<i + 1<<" ";
    }
    cout<<endl;
    cout<<ans.size()<<endl;
    for(auto i : ans)
    {
        cout<<i.first + 1<<" "<<i.second + 1<<endl;
    }
}