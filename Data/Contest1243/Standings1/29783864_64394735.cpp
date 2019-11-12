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
string s, t;
int a[30], b[30];
struct node {
    int l, r;
}ans[150];
inline void doit() {
    int n = read(), cnt = 0;
    cin >> s; cin >> t;
    memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
    for(int i = 0; i < n; ++i) a[s[i] - 'a'] ++;
    for(int i = 0; i < n; ++i) b[t[i] - 'a'] ++;
    for(int i = 0; i < 30; ++i) if((a[i] + b[i]) & 1) {
        cout << "No" << endl; return;
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; ++i)  
        if(s[i] != t[i]) {
            for(int j = i + 1; j < n; ++j) {
                if(s[j] == s[i]) {
                    ans[++cnt] = (node){j + 1, i + 1};
                    s[j] = t[i]; break;
                } else if(t[j] == s[i]) {
                    ans[++cnt] = (node){i + 2, j + 1};
                    ans[++cnt] = (node){i + 2, i + 1};
                    t[j] = s[i + 1]; s[i + 1] = t[i]; break;
                }
            }
        }
    cout << cnt << endl;
    REP(i, 1, cnt) cout << ans[i].l << " " << ans[i].r << endl;
}
int main() {   
    int T = read();
    while(T--) {
        doit();
    } 
	return 0;
}
