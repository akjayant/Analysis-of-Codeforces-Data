#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mx = 1e18 + 7;
int n, c[100001][3], mn = mx, b[100001], answ[100001];
vector<int> Adjlist[100001];

int ans(int ini, int lst1, int lst2, int p){
    bool ck[3];
    ck[0] = ck[1] = ck[2] = 0;
    ck[lst1] = ck[lst2] = 1;
    int tmp;
    if(ck[0] == 0) tmp = 0;
    else if(ck[1] == 0) tmp = 1;
    else tmp = 2;
    b[ini] = tmp;
    if(Adjlist[ini].size() == 1) return c[ini][tmp];
    if(Adjlist[ini][0] != p) return c[ini][tmp] + ans(Adjlist[ini][0], tmp, lst1, ini);
    else return c[ini][tmp] + ans(Adjlist[ini][1], tmp, lst1, ini);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[j][i];
        }
    }
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        Adjlist[x].push_back(y);
        Adjlist[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(Adjlist[i].size() >= 3){
            cout << -1;
            return 0;
        }
    }
    //cout << 0 << "\n";
    int root = -1;
    for(int i = 1; i <= n; i++){
        if(Adjlist[i].size() == 1){
            root = i;
            break;
        }
    }
    int x = Adjlist[root][0], y;
    if(Adjlist[x][0] != root) y = Adjlist[x][0];
    else y = Adjlist[x][1];
    //cout << y << "\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j) continue;
            b[root] = i;
            b[x] = j;
            if(mn > c[root][i] + c[x][j] + ans(y, j, i, x)){
                mn = c[root][i] + c[x][j] + ans(y, j, i, x);
                //cout << mn << " " << i << " " << j << " " << c[root][i] << " " << c[x][j] << "\n";
                for(int k = 1; k <= n; k++) answ[k] = b[k];
            }
        }
    }
    cout << mn << "\n";
    for(int i = 1; i <= n; i++) cout << answ[i] + 1 << " ";
}