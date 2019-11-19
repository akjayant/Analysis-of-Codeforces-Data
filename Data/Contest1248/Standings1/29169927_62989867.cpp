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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m;
long long ans, f[N], sum;
int main() {
	n = read(); m = read();
	f[0] = 2; f[1] = 2; REP(i, 2, max(n, m)) f[i] = (f[i - 1] + f[i - 2]) % mod;
	ans = (f[m] + f[n] - 2) % mod;
	printf("%lld\n", ans);
	return 0;
}