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

int main() {   
    int T = read();
    while(T--) {
        int n = read(), cnt = 0;
        int l = -1, r = 0;
        cin >> s; cin >> t;
        for(int i = 0; i < n; ++i) if(s[i] != t[i]) {
            if(l == -1) l = i;
            r = i;
            cnt ++;
        }
        if(cnt == 2) {
            if(s[l] == s[r] && t[l] == t[r]) cout << "Yes" << endl;
            else cout <<"No" << endl;
        }else cout << "No" << endl;
    } 
	return 0;
}
