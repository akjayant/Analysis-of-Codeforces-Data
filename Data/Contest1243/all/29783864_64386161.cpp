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
long long n0, n;
int p;
int main() {   
    scanf("%lld", &n0); n = n0;
    for(long long i = 2; i * i <= n; ++i) 
        if(n % i == 0) {
            p = i;
            n /= p;
            break;
        }
    if(n == n0) cout << n << endl;
    else {
        while(n % p == 0) n /= p;
        if(n == 1) cout << p << endl;
        else cout << 1 << endl;
    }
	return 0;
}
