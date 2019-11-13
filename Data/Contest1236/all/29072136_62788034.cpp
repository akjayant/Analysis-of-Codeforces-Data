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
#define int long long
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
const int MOD = 1e9 + 7;
#define ll long long
inline int pw(ll a,ll b,ll mod){
  ll r=1;
  while(b>0){
    if(b&1) r=(ll)r*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return r;
}

signed main() { 
    int n = read(), m = read();
    int a = (pw(2, m, MOD) - 1) % MOD;
    int b = pw(a, n, MOD);
    printf("%lld\n", b);
	return 0;
}
