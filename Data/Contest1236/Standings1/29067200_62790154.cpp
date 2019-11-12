#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, ans[305][305];
void init(){
    n = read();
}
void solve(){
    for (int i = 1; i <= n; ++i){
        if (i & 1){
            for (int j = (i - 1) * n + 1, k = 1; j <= i * n; ++j, ++k)
                ans[k][i] = j;

        }else {
            for (int j = (i - 1) * n + 1, k = n; j <= i * n; ++j, --k)
                ans[k][i] = j;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j < n; ++j)
            printf("%d ", ans[i][j]);
        printf("%d\n", ans[i][n]);
    }
}
int main(){
    init();
    solve();
    return 0;
}