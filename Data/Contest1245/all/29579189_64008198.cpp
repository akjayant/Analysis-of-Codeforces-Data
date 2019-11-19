/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;

int n;

pair<int, int> coord[2002];

ll cost1[2002], cost2[2002];

bool conn[2002];

vector<int>statii;
vector<pair<int, int> >muchii;

ll bst[2002];
ll tip[2002];

bool viz[2002];
ll dm(ll a, ll b)
{
    return abs(coord[a].fi - coord[b].fi) + abs(coord[a].se - coord[b].se);
}
int main()
{
    please followmeoninsta
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> coord[i].fi >> coord[i].se;
    for(int i = 1; i <= n; ++i)
        cin >> cost1[i];
    for(int i = 1; i <= n; ++i)
        cin >> cost2[i], bst[i] = cost1[i];
    set<pair<ll, int> >ord;
    for(int i = 1; i <= n; ++i)
        ord.insert({cost1[i], i});
    for(int x = 0; x < n; ++x)
    {
        pair<ll, int> pp = *ord.begin();
        ord.erase(pp);
        int i = pp.se;
        if(pp.fi < bst[i])
        {
            bst[i] = pp.fi;
            tip[i] = 0;
        }
        viz[i] = 1;
        for(int j = 1; j <= n; ++j)
        {
            if(viz[j])
                continue;
            ll costmch = 1LL * (cost2[i] + cost2[j]) * dm(i, j);
            if(costmch < bst[j])
            {
                ord.erase({bst[j], j});
                bst[j] = costmch;
                tip[j] = i;
                ord.insert({bst[j], j});
            }
        }
    }
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += bst[i];
        if(tip[i] == 0)
            statii.push_back(i);
        else
            muchii.push_back({i, tip[i]});
    }
    cout << sum << '\n';
    cout << statii.size() << '\n';
    for(int i = 0; i < statii.size(); ++i)
        cout << statii[i] << " ";
    cout << '\n';
    cout << muchii.size() << '\n';
    for(int i = 0; i < muchii.size(); ++i)
        cout << muchii[i].fi << " " << muchii[i].se << '\n';
    return 0;
}
