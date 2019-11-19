#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const int N = 2020;
int n;
PLL cts[N];
LL costs[N], ks[N];
int uf[N];
int find(int x)
{
    if(x != uf[x]) uf[x] = find(uf[x]);
    return uf[x];
}

LL dist(int i, int j)
{
    LL len = abs(cts[i].first - cts[j].first) + abs(cts[i].second - cts[j].second); 
    return len * (ks[i] + ks[j]);
    
}

bool cmp(vector<LL>& a, vector<LL>& b)
{
    return a[2] < b[2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> cts[i].first >> cts[i].second;
    }
    for(int i = 1; i <= n; i++) cin >> costs[i];
    for(int i = 1; i <= n; i++) cin >> ks[i];
    
    vector<vector<LL>> pipes;
    for(LL i = 1; i <= n; i++)
    {
        pipes.push_back({0LL, i, costs[i]});
        uf[i] = i;
        for(LL j = i + 1; j <= n; j++)
        {
            pipes.push_back({i, j, dist(i, j)});
        }
    }
    sort(pipes.begin(), pipes.end(), cmp);
    
    LL res = 0;
    int sta = 0, e = 0;
    vector<PLL> edges;
    vector<LL> cities;
    for(auto pipe : pipes)
    {
        int x = find(pipe[0]), y = find(pipe[1]);
        if(x != y)
        {
            if(pipe[0] == 0) 
            {
                sta++;
                cities.push_back(pipe[1]);
            }
            else 
            {
                e++;
                edges.push_back({pipe[0], pipe[1]});
            }
            res += pipe[2];
            uf[x] = y;
        }
    }
    cout << res << endl;
    cout << sta << endl;
    for(int i : cities) cout << i << " ";
    cout << endl;
    cout << e << endl;
    for(auto& e : edges) cout << e.first << " " << e.second << endl;
    return 0;
}