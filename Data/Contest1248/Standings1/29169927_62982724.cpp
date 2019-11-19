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
int a[N], n;
LL l1, l2, r1, r2, ans, sum;
int main() {
	n = read();
	REP(i, 1, n) a[i] = read(), sum = sum + a[i];
	if(n == 1) {
		cout << 1LL * a[1] * a[1] << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if(n % 2) {
		int k = n / 2;
		for(int i = 1; i <= k; ++i) l1 = l1 + a[i];
		for(int i = k + 1; i <= n; ++i)  r1 = r1 + a[i];
		for(int i = 1; i <= k + 1; ++i) l2 = l2 + a[i];
		for(int i = k + 2; i <= n; ++i) r2 = r2 + a[i];
		ans = sum * sum - min(2 * l1 * r1, 2 * l2 * r2);
	} else {
		int k = n / 2;
		for(int i = 1; i <= k; ++i) l1 = l1 + a[i];
		for(int i = k + 1; i <= n; ++i)  r1 = r1 + a[i];
		ans = sum * sum - 2 * l1 * r1;
	}
	printf("%lld\n", ans);
	return 0;
}