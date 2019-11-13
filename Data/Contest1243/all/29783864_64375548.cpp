#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define LL long long
#define lowbit(x) x &(-x)
//think twice code once
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}
const int N = 1e3 + 3;
int n, a[N];
int ans = 0;
int main() {   
    int T = read();
    while(T--) {
        n = read(); REP(i, 1, n) a[i] = read();
        sort(a + 1, a + n + 1);
        ans = 0;
        REP(i, 1, n) 
            ans = max(ans, min(a[i], n - i + 1));
        printf("%d\n", ans);
    }
	return 0;
}
