#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define eps 1e-6
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
const int maxN = 1e5 + 7;
const ll mod = 1e9 + 7;
int N;
ll dp[maxN];
char s[maxN];
int main()
{
    scanf("%s", s + 1);
    N = (int)strlen(s + 1);
    bool flag = true;
    for(int i=1; i<=N; i++) if(s[i] == 'w' || s[i] == 'm') { flag = false; break; }
    if(!flag) { printf("0\n"); return 0; }
    dp[0] = dp[1] = 1;
    for(int i=1; i<=N; i++)
    {
        if(s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n')) dp[i] = (dp[i-1] + dp[i-2])%mod;
        else dp[i] = dp[i-1];
    }
    printf("%lld\n", dp[N]);
    return 0;
}
