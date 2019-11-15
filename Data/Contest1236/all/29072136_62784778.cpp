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
int a = read(), b = read(), c = read();
    int t = min(b, c / 2);
    b -= t;
    int x = min(a, b / 2);
    int ans = x * 3 + t * 3;
    cout << ans << endl;
    }
    

	return 0;
}
