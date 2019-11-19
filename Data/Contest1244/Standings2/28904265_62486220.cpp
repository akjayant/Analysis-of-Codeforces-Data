#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e16

using namespace std;

ll n,k,ar[N];
ll c[N][3];
vector < vector < ll > > graph(N);
ll deg[N],root;
vector < ll > pos;
ll color[N];
bool ccc;

ll calc(ll cur,ll par,ll p)
{
    ll res = c[cur][pos[p]];
    color[cur] = pos[p]+1;
    p++;
    p%=3;

    rep(i,0,graph[cur].size())
    {
        ll v= graph[cur][i];

        if(v == par)
            continue;

        res += calc(v,cur,p);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    rep(j,0,3)
    {
        rep(i,1,n+1)
        {
            cin >> c[i][j];
        }
    }

    ll a,b;
    rep(i,0,n-1)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    bool can = true;

    rep(i,1,n+1)
    {
        if(deg[i] >= 3)
            can = false;
    }

    if(!can)
    {
        cout << -1 << endl;
        return 0;
    }

    rep(i,1,n+1)
    {
        if(deg[i] == 1)
        {
            root = i;
            break;
        }
    }

    ll ans = INF;
    vector < ll > best;
    rep(i,0,3)
    pos.push_back(i);

    do{
            if(calc(root,root,0) < ans)
            {
                ans = calc(root,root,0);
                best = pos;
            }
    }while(next_permutation(pos.begin(),pos.end()));

    cout << ans << endl;

    ccc=true;
    pos = best;
    calc(root,root,0);
    rep(i,1,n+1)
        cout << color[i] << " ";

    return 0;
}

