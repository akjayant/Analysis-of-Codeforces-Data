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


string s;

int main() { 
	int T = read();
	while(T--) {
		int n = read();
		cin >> s; int l = 0, r = 0;
		for(int i = 0; i < s.length() - 1; ++i) if(s[i] == '1') {
			l = i + 1;
			break;
		}
		for(int i = s.length() - 1; i >= 0; --i) if(s[i] == '1') {
			r = i + 1;
			break;
		}
		int ans = n;
		if(l) {
			ans = max(ans, n + 1);
			ans = max(ans, (n - l + 1) * 2);
		}
		if(r) {
			ans = max(ans, n + 1);
			ans = max(ans, r * 2);
		}
		cout << ans << endl;
	}  
	return 0;
}
