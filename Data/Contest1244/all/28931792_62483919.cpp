#include <bits/stdc++.h>

#define int long long
#define loop(i,n) for(int i = 0; i<n; ++i)
#define all(a) a.begin(),a.end()
#define FOR(i,n,m) for(int i = n; i<m; ++i)
#define rall(a) a.rbegin(),a.rend()

using namespace std;

vector <vector <int> > g;
vector <int> cl;
vector <bool> used;

void dfs(int v, int p, int cp, int cpp)
{
    int ncl;
    loop(hui,3) if (hui != cp && hui != cpp) ncl = hui;
    cl[v] = ncl;
    for(auto u:g[v])
    {
        if (u!=p) dfs(u,v,ncl,cp);
    }
}

signed main()
{
    int n;
    cin >> n;
    g.resize(n);
    cl.resize(n);
    used.resize(n);
    vector <int> c1(n),c2(n),c3(n);
    loop(i,n) cin >> c1[i];
    loop(i,n) cin >> c2[i];
    loop(i,n) cin >> c3[i];
    loop(i,n-1)
    {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    loop(i,n) if (g[i].size() > 2)
    {
        cout << -1;
        return 0;
    }
    int ver1,ver2,ver3,ppc = 1e14+1;
    loop(i,n) if (g[i].size() == 1) {
        ver1 = i;
        break;
    }
    ver2 = g[ver1][0];
    vector <int> FAK(n);
    loop(i,2) if (g[ver2][i] != ver1) ver3 = g[ver2][i];
    for(int i = 0; i<3; ++i)
    {

        for(int j = 0; j<3; ++j)
        {
            used.assign(n,false);
            cl.assign(n,-1);
            cl[ver1] = i;
            if (j != cl[ver1])
            {
                cl[ver2] = j;
                int ans = 0;
                dfs(ver3,ver2,cl[ver2],cl[ver1]);
                loop(jepa,n) if(cl[jepa] == 0) ans += c1[jepa]; else if (cl[jepa] == 1) ans += c2[jepa]; else if (cl[jepa] == 2) ans += c3[jepa];
                if (ppc > ans){
                    ppc = ans;
                    loop(q,n) FAK[q] = cl[q] + 1;
                }
            }
        }

    }
    cout << ppc << endl;
    loop(i,n) cout << FAK[i] << ' ';
}
