#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

pair<int,int> arr[2100];
int c[2100],k[2100];
int visit[2100];
long long cost[2100];
int par[2100];
priority_queue<pair<long long,pair<int,int> > , vector<pair<long long,pair<int,int>> >, greater<pair<long long,pair<int,int>> > > q;
vector<int>a;
vector<pair<int,int> > b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 1 ; i<=n ; ++i) cin>>arr[i].first>>arr[i].second;
    for(int i = 1 ; i<=n ; ++i) cin>>c[i];
    for(int i = 1 ; i<=n ; ++i) cin>>k[i];

    for(int i = 1 ; i<=n ; ++i) q.push({c[i], {i,i}});

    while(!q.empty())
    {
        auto x = q.top();
        q.pop();
        if(visit[x.second.first]) continue;
        visit[x.second.first] = 1;
        cost[x.second.first] = x.first;
        par[x.second.first] = x.second.second;
        for(int i = 1 ; i<=n; ++i)
        {
            if(visit[i]) continue;
            q.push({(k[x.second.first] + k[i])*1ll*(abs(arr[x.second.first].first - arr[i].first) + abs(arr[x.second.first].second - arr[i].second)), {i,x.second.first}});
        }
    }

    long long ans = 0;
    for(int i = 1 ; i<=n ; ++i) ans += cost[i];
    cout<<ans<<endl;
    for(int i = 1 ; i<=n ; ++i)
    {
        if(par[i] == i) a.push_back(i);
        else b.push_back({i,par[i]});
    }
    cout<<a.size()<<endl;
    for(int i = 0 ; i<a.size() ;++i) cout<<a[i]<<" \n"[i+1==a.size()];
    cout<<b.size()<<endl;
    for(int i = 0 ; i<b.size() ;++i) cout<<b[i].first<<" "<<b[i].second<<endl;

    return 0;
}
