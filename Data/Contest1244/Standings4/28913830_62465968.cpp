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
		int a = read(), b = read(), c = read(), d = read(), k = read();
		int x = (int)(a + c - 1) / c, y = (int)(b + d - 1) / d;
		//cout << k << endl;
		if((x + y) <= k) 
			cout << k - y << " " << y << endl;
		 else cout << -1 << endl;
	}
	
	return 0;
}
