#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>

const int N = 1e5 + 1000, mod = 1e9 + 7;
vector <int> vec[N];
ll a[N][4], n;
int was[N], b[N];

ll bin_pow(int x, int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(y % 2 == 0){
        ll z = bin_pow(x, y / 2);
        return (z * z) % mod;
    }
    return (bin_pow(x, y - 1) * x) % mod;
}

ll dfs(int x, int pr, int v, int pv){
    for(int i = 0; i < vec[x].size(); i++)
        if(vec[x][i] != pr)
            for(int j = 1; j <= 3; j++)
                if(j != v && j != pv)
                    return (dfs(vec[x][i], x, j, v) + a[vec[x][i]][j]);
    return 0;
}

void go(int x, int pr, int v, int pv){
    for(int i = 0; i < vec[x].size(); i++)
        if(vec[x][i] != pr)
            for(int j = 1; j <= 3; j++)
                if(j != v && j != pv){
                    b[vec[x][i]] = j;
                    go(vec[x][i], x, j, v);
                }
}

int main(){
    boost;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i][2];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i][3];
    }
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        vec[x].pb(y);
        vec[y].pb(x);
        was[x]++;
        was[y]++;
        if(was[x] >= 3 || was[y] >= 3){
            cout << -1;
            return 0;
        }
    }
    int t = 0;
    for(int i = 1; i <= n; i++){
        if(was[i] == 1){
            t = i;
            break;
        }
    }
    ll ans = 1e17, x = 0, y = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(i != j){
                ll k = dfs(vec[t][0], t, i, j) + a[t][j] + a[vec[t][0]][i];
                if(ans > k){
                    ans = k;
                    x = i;
                    y = j;
                }
            }
        }
    }
    cout << ans << "\n";
    b[vec[t][0]] = x;
    b[t] = y;
    go(vec[t][0], t, x, y);
    for(int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
