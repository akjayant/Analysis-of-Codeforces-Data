/*
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int G[20][20];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool ok(int x, int y, int r, int c){
    return !(x < 1 || x > r || y < 1 || y > c);
}

bool check(int r, int c){
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            int cnt = 0;
            for(int k = 0; k < 4; ++k){
                int nx = i + dx[k], ny = j + dy[k];
                if(ok(nx, ny, r, c) && G[nx][ny] == G[i][j])  ++cnt;
            }
            if(cnt >= 2)  return false;
        }
    }
    return true;
}

void bf(){
    for(int i = 2; i <= 2; ++i){
        for(int j = 1; j <= 10; ++j){
            int ans = 0;
            for(int s = 0; s < (1<<(i*j)); ++s){
                for(int k = 0; k < i*j; ++k){
                    int r = k/j + 1, c = k%j + 1;
                    if(s & (1<<k))  G[r][c] = 1;
                    else G[r][c] = 0;
                }
                if(check(i,j))  ++ans;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    LL ans = 2;
    LL add1 = 0;
    if(n == 1)  add1 = 0;
    else if(n == 2)  add1 = 2;
    else if(n == 3)  add1 = 4;
    else{
        add1 = 4;
        LL a = 2, b = 2, c;
        for(int i = 4; i <= n; ++i){
            c = a;
            a = (a + b) % MOD;
            b = c;
            add1 = (add1 + a) % MOD;
        }
    }

    LL add2 = 0;
    if(m == 1)  add2 = 0;
    else if(m == 2)  add2 = 2;
    else if(m == 3)  add2 = 4;
    else{
        add2 = 4;
        LL a = 2, b = 2, c;
        for(int i = 4; i <= m; ++i){
            c = a;
            a = (a + b) % MOD;
            b = c;
            add2 = (add2 + a) % MOD;
        }
    }
//    cout << add1 << " " << add2 << endl;
    printf("%lld\n", ((ans + add1) % MOD + add2) % MOD);
    return 0;
}


/*
2
4    2
6    2
10   4
16   6
26   10
42   16
68   26
110  42
178  68
288  110
466
754
1220
1974
*/