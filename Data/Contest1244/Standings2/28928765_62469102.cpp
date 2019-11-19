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
int n;
char s[1005];
void init(){
    scanf("%d%s", &n, s);
}
void solve(){
    int ans = 0;
    int le = n, re = -1;
    for (int i = 0; i < n; ++i) 
        if (s[i] == '1') {
            le = i;
            break;
        }
    for (int i = n -1 ; i>= 0; --i) 
        if (s[i] == '1') {
            re = i;
            break;
        }
    ans = n;
    ans = max(ans, 2 * max(n - le, re + 1));
    printf("%d\n", ans);
}
int main(){
     int T = read();
    while (T--){
init();
    solve();
    }
    return 0;
}