#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

const int N = 1e6+100;

int cost[N][4];
vector<int> g[N];
int deg[N];
int c[N];

ll dfs(int u , int par , vector<int> &per, int pos){
    c[u] = per[pos];
    ll ans = cost[u][c[u]];
    for(auto v : g[u]){
        if(v != par)
            ans += dfs(v , u , per , (pos + 1) % 3);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int j = 1; j <= 3; j++)
        for(int i = 1; i <= n; i++){
            cin >> cost[i][j];
        }

    for(int i = 0; i < n - 1; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int maxi = 0;
    int root = -1;
    for(int i = 1; i <= n; i++){
        maxi = max(maxi , deg[i]);
        if(deg[i] == 1){
            root = i;
        }
    }

    if(root == -1 || maxi > 2){
        cout << -1 << endl;
        return 0;
    }


    vector<int> per = {1 , 2 , 3};
    vector<int> good_per;
    ll mini = 1LL << 60;
    do{
        ll get = dfs(root , -1 , per, 0);
        if(get < mini){
            mini = get;
            good_per = per;
        }
    }while(next_permutation(per.begin(), per.end()));

    dfs(root , -1 , good_per, 0);
    cout << mini  << endl;
    for(int i = 1; i <= n; i++){
        cout << c[i] << " ";
    }
    cout << endl;


}
