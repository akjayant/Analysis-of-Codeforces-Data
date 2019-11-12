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
int n, m;
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = 1ll * res * a % 1000000007;
        a = 1ll * a * a % 1000000007, b >>= 1;
    }
    return res;
}
void init(){
    n = read(), m = read();
}
void solve(){
    int res = (poww(2, m) - 1 + 1000000007) % 1000000007;
    res = poww(res, n);
    printf("%d\n", res);
}
int main(){
    init();
    solve();
    return 0;
}