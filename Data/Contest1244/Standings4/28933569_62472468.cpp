#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long LL;

const int N = 1010;

int n;
char s[N];
int a[N];

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
		scanf("%d" , &T);
		while (T--) {
				scanf("%d%s" , &n , s);
				for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
				int fir = n , sec = -1;
				for (int i = 0; i < n; ++i)
						if (a[i]) {
								fir = i;
								break;
						}
				for (int i = n - 1; i >= 0; --i)
						if (a[i]) {
								sec = i;
								break;
						}
				printf("%d\n" , max(n , 2 * max(n - fir , sec + 1)));
		}
	  return 0;
	
}
