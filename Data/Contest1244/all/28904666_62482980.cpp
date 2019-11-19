/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)
#define pb push_back

using namespace std;

int n;
int cost[5][100002];
vector<int>tr[100002];

int color[100002];

ll mincost, cosst;

int fndnxt(int a, int b)
{
    if(a > b)
        swap(a, b);
    if(a == 1 && b == 2)
        return 3;
    if(a == 1 && b == 3)
        return 2;
    if(a == 2 && b == 3)
        return 1;
}
int main()
{
    please followmeoninsta

    cin >> n;
    for(int bfr = 1; bfr <= 3; ++bfr)
        for(int i = 1; i <= n; ++i)
            cin >> cost[bfr][i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        tr[a].pb(b);
        tr[b].pb(a);
        if(tr[a].size() == 3)
        {
            cout << -1;
            return 0;
        }
        if(tr[b].size() == 3)
        {
            cout << -1;
            return 0;
        }
    }
    int root = 1;
    for(int i = 1; i <= n; ++i)
        if(tr[i].size() == 1)
            root = i;
    vector<int>lant;
    lant.pb(root);
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < tr[lant.back()].size(); ++j)
        {
            int nod = tr[lant.back()][j];
            if(i > 1)
            {
                if(nod == lant[i-2])
                    continue;
            }
            lant.pb(nod);
            break;
        }
    }
    mincost = (1LL<<60);
    for(int col1 = 1; col1 <= 3; ++col1)
        for(int col2 = 1; col2 <= 3; ++col2)
        {
            if(col1 == col2)
                continue;
            cosst = cost[col1][lant[0]] + cost[col2][lant[1]];
            int prv1 = col1;
            int prv2 = col2;
            for(int i = 2; i < n; ++i)
            {
                int nrw = fndnxt(prv1, prv2);
                cosst += cost[fndnxt(prv1, prv2)][lant[i]];
                prv1 = prv2;
                prv2 = nrw;
            }
            if(cosst <= mincost)
            {
                mincost = cosst;
                color[lant[0]] = col1;
                color[lant[1]] = col2;
                prv1 = col1;
                prv2 = col2;
                for(int i = 2; i < n; ++i)
                {
                    int nrw = fndnxt(prv1, prv2);
                    color[lant[i]] = nrw;
                    prv1 = prv2;
                    prv2 = nrw;
                }
            }
        }
    cout << mincost << '\n';
    for(int i = 1; i <= n; ++i)
        cout << color[i] << " ";
    return 0;
}
