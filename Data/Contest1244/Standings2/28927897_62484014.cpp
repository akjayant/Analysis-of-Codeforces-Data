#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+100;
long long int p[10][N], co[N];
long long int cost;
vector<long long int> v[N], c, mas;

void dfs(long long int x, long long int px, long long int d) {
    cost+=p[c[d%3]][x];
    mas[x]=c[d%3];
    for(int u: v[x])
        if(u!=px)
            dfs(u,x,d+1);
}

int main () {
    ios::sync_with_stdio(0);
    c={0,1,2};
    long long int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        mas.push_back(-1);
    for(int i = 0 ; i < n ; i++ )
        cin >> p[0][i];
    for(int i = 0 ; i < n ; i++ )
        cin >> p[1][i];
    for(int i = 0 ; i < n ; i++ )
        cin >> p[2][i];
    for(int i = 0 ; i < n-1 ; i++ ) {
        long long int u1, u2;
        cin >> u1 >> u2;
        u1--;
        u2--;
        v[u1].push_back(u2);
        v[u2].push_back(u1);
    }
    long long int mx =-1, le;
    for(int i = 0 ; i < n ; i++ ) {
        mx=max(mx,1ll*v[i].size());
        if(v[i].size()==1)
            le=i;
    }
    if(mx>2) {
        cout << -1;
        return 0;
    }

    long long int ans = 1e18;
    vector<long long int>ja;
    for(int i = 0 ; i < 6 ; i++ ) {
        cost=0;
        dfs(le,-1,0);
      //  cout << cost << ' ' << ans << ' ' << c[0] << ' ' << c[1] <<  ' '  << c[2] << '\n';
        if(ans>cost) {
            ja=mas;
            ans=cost;
        }
        next_permutation(c.begin(),c.end());
    }
    cout << ans << '\n';
    for(int u : ja)
        cout << u+1 << ' ';
}

