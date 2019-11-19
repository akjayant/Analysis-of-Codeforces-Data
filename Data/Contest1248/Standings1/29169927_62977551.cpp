#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define LL long long
#define lowbit(x) x &(-x)
template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(y < x) x = y;}
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}
int main() {
	int T = read();
	while(T--) {
		int n = read(); int a = 0, b = 0, c = 0, d = 0;
		REP(i, 1, n) {
			int x = read();
			if(x % 2) a ++;
			else b ++;
		}
		int m = read();
		REP(i, 1, m) {
			int x = read();
			if(x % 2) c ++;
			else d ++;
		}
		long long ans = 1LL * a * c + 1LL * b * d;
		printf("%lld\n", ans);		
	}
	return 0;
}