#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long int uLL;
typedef unsigned int uint;

const int N = 100007;
const LL INF = 1000000000000007;

vector <int> V[N];
LL dp[N][6], c[N][3];
int deg[N], kolorek[N];
void DFS(int v, int ojciec){
    //cout << "V " << v << '\n';
    for(auto u: V[v]){
        if(u != ojciec){
            DFS(u, v);
            dp[v][0] = dp[u][3];
            dp[v][1] = dp[u][5];
            dp[v][2] = dp[u][1];
            dp[v][3] = dp[u][4];
            dp[v][4] = dp[u][0];
            dp[v][5] = dp[u][2];
        }
    }
    dp[v][0] += c[v][0];
    dp[v][1] += c[v][0];
    dp[v][2] += c[v][1];
    dp[v][3] += c[v][1];
    dp[v][4] += c[v][2];
    dp[v][5] += c[v][2];
    /*for(int i = 0; i < 6; i++){
        cout << dp[v][i] << " ";
    }
    cout << '\n';*/
    return;
}
void kolor(int v, int ojciec, int pam){
    if(pam == 0){
        kolorek[v] = 1;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 3);
            }
        }
    }
    if(pam == 1){
        kolorek[v] = 1;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 5);
            }
        }
    }
    if(pam == 2){
        kolorek[v] = 2;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 1);
            }
        }
    }
    if(pam == 3){
        kolorek[v] = 2;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 4);
            }
        }
    }
    if(pam == 4){
        kolorek[v] = 3;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 0);
            }
        }
    }
    if(pam == 5){
        kolorek[v] = 3;
        for(auto u: V[v]){
            if(u != ojciec){
                kolor(u, v, 2);
            }
        }
    }
}
int n;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int j = 0; j < 3; j++){
        for(int i = 1; i <= n; i++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int start = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] > 2){
            cout << -1 << '\n';
            return 0;
        }
        if(deg[i] == 1){
            start = i;
        }
    }
    DFS(start, start);
    LL wyn = 0;
    for(int i = 0; i < 6; i++){
        if(dp[start][wyn] > dp[start][i]){
            wyn = i;
        }
    }
    cout << dp[start][wyn] << '\n';
    kolor(start, start, wyn);
    for(int i = 1; i <= n; i++){
        cout << kolorek[i] << " ";
    }
    cout << '\n';
    return 0;
}
