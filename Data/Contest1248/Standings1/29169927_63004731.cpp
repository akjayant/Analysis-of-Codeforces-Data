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
const int N = 501;
string s;
int n, a[N], b[N], f[N], g[N], ff[N], gg[N], fff[N], ggg[N];
int ans, l0 = 1, r0 = 1;
int main() {
	cin >> n; cin >> s;
	REP(i, 1, n) {
		if(s[i - 1] == '(') a[i] = 1;
		else a[i] = -1;
	} 
	REP(i, 1, n) b[i] = a[i];
	int haha;
	for(register int l = 1; l <= n - 1; ++l)
		for(register int r = l + 1; r <= n; ++r) {
			b[l] = a[r]; b[r] = a[l];
			f[0] = 0; g[n + 1] = 0; ff[0] = 0; gg[n + 1] = 0;
			for(register int i = 1; i <= n; ++i) {
				f[i] = f[i - 1] + b[i];
				ff[i] = min(ff[i - 1], f[i]);
			}
			for(register int i = n; i >= 1; --i) {
				g[i] = g[i + 1] + b[i];
				gg[i] = min(gg[i + 1], 0) + b[i];
			}
			int sum = 0;
			for(register int i = n + 1; i >= 2; --i) if((g[i] + ff[i - 1]) >= 0) {
				if((f[i - 1] + g[i]) == 0 && (gg[i] >= 0)) {
					sum++;
					//cout << i << endl;
					//cout << f[i - 1] << " " << g[i] << endl; 
					//cin >> haha;
				}
			}
			b[l] = a[l]; b[r] = a[r];
			if(sum > ans) {
				ans = sum;
				l0 = l;
				r0 = r;
			}
		}
	int l = 1, r = 1;
	b[l] = a[r]; b[r] = a[l];
			f[0] = 0; g[n + 1] = 0; ff[0] = 0; gg[n + 1] = 0;
			REP(i, 1, n) {
				f[i] = f[i - 1] + b[i];
				ff[i] = min(ff[i - 1], f[i]);
			}
			PER(i, n, 1) {
				g[i] = g[i + 1] + b[i];
				gg[i] = min(gg[i + 1], 0) + b[i];
			}
			int sum = 0;
			PER(i, n + 1, 2) if((g[i] + ff[i - 1]) >= 0) {
				if((f[i - 1] + g[i]) == 0 && (gg[i] >= 0)) {
					sum++;
					//cout << i << endl;
					//cout << f[i - 1] << " " << g[i] << endl; 
					//cin >> haha;
				}
			}
			b[l] = a[l]; b[r] = a[r];
			if(sum > ans) {
				ans = sum;
				l0 = l;
				r0 = r;
			}
	cout << ans << endl;
	cout << l0 << " " << r0 << endl;
	return 0;
}