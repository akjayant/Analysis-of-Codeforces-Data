#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int n, m, k;
vector<int> row[N], col[N];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++ i){
        int x, y; scanf("%d%d", &x, &y);
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for(int i = 1; i <= n; ++ i){
        row[i].push_back(0);
        row[i].push_back(m+1);
        sort(row[i].begin(), row[i].end());
    }
    for(int i = 1; i <= m; ++ i){
        col[i].push_back(0);
        col[i].push_back(n+1);
        sort(col[i].begin(), col[i].end());
    }
    int up = 2, down = n, mleft = 1, mright = m;
    int x = 1, y = 1;
    ll vis = 1;
    int first = 1;
    for(;;){
        int nowx = x, nowy = y;
        int movetoy = row[x][lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin()];
        movetoy = min(movetoy - 1, mright);
        mright = min(mright, movetoy - 1);
        vis += movetoy - y;
        if(y == movetoy && first != 1){
            break;
        }
        first = 0;
        y = movetoy;


        int movetox = col[y][lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin()];
        movetox = min(movetox - 1, down);
        down = min(down, movetox - 1);
        vis += movetox - x;
        if(x == movetox) break;
        x = movetox;


        movetoy = row[x][lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin() - 1];
        movetoy = max(mleft, movetoy+1);
        mleft = max(mleft, movetoy+1);
        vis += y - movetoy;
        if(y == movetoy) break;
        y = movetoy;

        movetox = col[y][lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin() - 1];
        movetox = max(up, movetox+1);
        up = max(up, movetox + 1);
        vis += x - movetox;
        if(x == movetox) break;
        x = movetox;

        if(nowx == x && nowy == y) break;

    }
    puts(vis + k == 1ll * n * m ? "Yes" : "No");
    return 0;
}