#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long LL;

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

int main() {
		
		int T;
		read(T);
		while (T--) {
				int a , b , c , d , k;
				read(a); read(b); read(c); read(d); read(k);
				bool sol = 0;
				for (int i = 0; i <= k; ++i) {
						if (c * i >= a && d * (k - i) >= b) {
								printf("%d %d\n" , i , k - i);
								sol = 1;
								break;
						}
				}
				if (!sol) printf("-1\n");
		}
		
	  return 0;
	
}
