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
int a, b, c;
void init(){
    a = read(), b = read(), c = read();
}
void solve(){
    int ans = 0;
    for (int i = 1; i <= b; ++i){
        if (c < 2) break;
        ans += 3, c -= 2;
    }
    b -= ans / 3;
    for (int i = 1; i <= a; ++i){
        if (b < 2) break;
        ans += 3, b -= 2;
    }
    
    printf("%d\n", ans);
}
int main(){
    int t = read();
    while (t--){
init();
    solve();
    }
    
    return 0;
}