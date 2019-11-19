#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0){
        x=1; y=0;
        return a;
    }
    LL r=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    LL n, p, w, d; cin >> n >> p >> w >> d;
    LL x0, y0;
    if(p / w > n) {
        cout << -1 << endl;
        return 0;
    }
    LL gcd = exgcd(w, d, x0, y0);
    if(p % gcd != 0) {
        cout << -1 << endl;
        return 0;
    }else {
        LL mul = p / gcd;
        LL inc_x = d / gcd;
        LL inc_y = w / gcd;
        y0 %= inc_y;
        y0 += inc_y;
        y0 %= inc_y;
        y0 = (y0*(mul%inc_y))%inc_y;
        LL tgtx0, tgty0;
        tgty0 = y0;
        // w * x + d * y == p
        tgty0 = (y0 % inc_y + inc_y) % inc_y;
        tgtx0 = (p - tgty0 * d ) / w;
        if(tgtx0 * w + tgty0 * d == p && tgtx0 >= 0 && tgty0 >= 0 && tgtx0 + tgty0 <= n) {
            cout << tgtx0 << " " << tgty0 << " " << n - tgtx0 - tgty0 << endl;
        } else {
            cout << -1 << endl;
        }
    }
     

    return 0;
}
