#include<bits/stdc++.h>
using namespace std;
 
#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif
 
typedef long long LL;

LL n , p , w , d;
 
template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

inline LL mul(LL x,LL y,LL p){
    LL res = 0 , sign = 0;
    if (y < 0) y = -y , sign = 1;
    while(y){
        if(y&1)res=(res+x)%p;
        x=(x<<1LL)%p; y>>=1;
    }
    res=(res%p+p)%p;
		if (sign)res=(p-res)%p;
		return res;
}

inline LL exgcd(LL a , LL b , LL &x , LL &y) {
		if (b == 0) {
				x = 1;
				y = 0;
				return a;
		} else {
				LL gc = exgcd(b , a % b , y , x);
				y -= a / b * x;
				return gc;		
		}
}

int main() {
		
		read(n); read(p); read(w); read(d);
		LL x = 0 , y = 0;
		LL r = exgcd(d , w , x , y);
		LL t = w / r;
		if (p % r) {
				printf("-1\n");
				return 0;
		}
    LL ansx = (mul(p / r , x , t) + t) % t;
    LL ansy = (p - 1LL * ansx * d) / w;
    if (ansx + ansy <= n && ansx >= 0 && ansy >= 0 && 1ll * ansx * d + 1ll * ansy * w == p)
    		printf("%I64d %I64d %I64d\n" , (long long)ansy , (long long)ansx , (long long)n - (long long)ansx - (long long)ansy);
    else printf("-1\n");
    
	  return 0;
	
}