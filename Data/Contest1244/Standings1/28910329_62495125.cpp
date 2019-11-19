#pragma GCC optimize("2,Ofast,inline")
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e5+10;
const LL mod=1e9+7;
const LL inf=0x3f3f3f;
const double eps=1e-9;
using namespace std;
template<typename tp> inline void read(tp &x)
{
    x=0;char c=getchar();
    bool f=0; for(; c<'0'||c>'9'; f|=(c=='-'),c = getchar());
    for(; c>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0',c = getchar());
    if(f) x=-x;
}
LL n, p, w, d, x, y, gcdd;
LL exgcd(LL a, LL b, LL &x, LL &y) 
{
    LL ret;
    if(!b) {ret = a; x = 1, y = 0;} 
    else {ret = exgcd(b, a % b, x, y);LL tmp = x;x = y;y = tmp - (a / b) * y;}
    return ret;
}
void solve()
{
    LL flaga = w / gcdd, flagb = d / gcdd;
    x = x % flagb * ((p / gcdd) % flagb);
	x = (x % flagb + flagb) % flagb;
	y = (p - w * x) / d;
	if(n >= x + y && x >= 0 && y >= 0){ printf("%lld %lld %lld\n", x, y,  n - x - y); exit(0);}
	y = (y % flaga + flaga) % flaga;
	x = (p - d * y) / w;
	if(n >= x + y && x >= 0 && y >= 0) { printf("%lld %lld %lld\n", x, y, n - x - y); exit(0);}
}
int main() 
{
	read(n),read(p),read(w),read(d);
    gcdd = exgcd(w, d, x, y);
    if(p % gcdd) return 0 * printf("-1\n");
	solve();
	puts("-1");
    return 0;
}
