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
ll n, p, w, d;
ll extgcd(ll a, ll b, ll &x, ll &y){
    if (b == 0){
        x = 1, y = 0;
        return a;
    }else {
        ll d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}
void init(){
    cin >> n >> p >> w >> d;
}
void solve(){
    ll xx, yy;
    ll dd = extgcd(w, d, xx, yy);
    if (p % dd != 0){
        printf("-1\n");
        return ;
    }else {
        ll ww = w / dd, d_ = d / dd;

        ll xx1 = (xx * ((p / dd) % d_) % d_ + d_) % d_, yy1 = (p - w * xx1) / d;
        if (xx1 >= 0 && yy1 >= 0 && xx1 + yy1 <= n){
            printf("%I64d %I64d %I64d\n", xx1, yy1, n - xx1 - yy1);
            return ;
        }
        ll yy2 = (yy * ((p / dd) % ww) % ww + ww) % ww, xx2 = (p - d * yy2) / w;
        if (xx2 >= 0 && yy2 >= 0 && xx2 + yy2 <= n){
            printf("%I64d %I64d %I64d\n", xx2, yy2, n - xx2 - yy2);
            return ;
        }
    }
    printf("-1\n");
            return ;
}
int main(){
    init();
    solve();
    return 0;
}