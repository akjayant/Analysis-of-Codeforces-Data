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
int a, b, c, d, k;
void init(){
    a = read(), b = read(), c = read(), d = read(), k = read();

}
void solve(){
    int c1 = (a - 1) / c + 1, c2 = (b - 1 ) / d + 1;
    if (c1 + c2 > k) {
        printf("-1\n");

    }else {
        printf("%d %d\n", c1, c2);
    }
}
int main(){
    int T = read();
    while (T--){
init();
    solve();
    }
    
    return 0;
}