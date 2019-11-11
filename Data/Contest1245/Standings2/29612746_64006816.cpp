
#include <iostream>  // C++ I/O
#include <fstream>  // File I/O
#include <sstream>  // String stream I/O
#include <iomanip>  // C++ I/O manipulator

#include <cstdlib>  // C library
#include <cstdio>  // C I/O
#include <ctime>  // C time
#include <cmath>  // Math library
#include <cstring>  // C strings

#include <vector>  // Vector
#include <queue>  // Queue
#include <stack>  // Stack
#include <map>  // Map
#include <set>  // Set
#include <algorithm>  // Algorithms

using namespace std;

#define reps(_var,_begin,_end,_step)  for (int _var = (_begin);  \
    _var <= (_end); _var += (_step))
#define reps_(_var,_end,_begin,_step)  for (int _var = (_end);  \
    _var >= (_begin); _var -= (_step))
#define rep(_var,_begin,_end)  reps(_var, _begin, _end, 1)
#define rep_(_var,_end,_begin)  reps_(_var, _end, _begin, 1)
#define minimize(_var,_targ)  _var = min(_var, _targ)
#define maximize(_var,_targ)  _var = max(_var, _targ)

typedef unsigned long long ull;
typedef long long lli, ll;
typedef double llf;

template <typename typ>
void memclr(typ p) {
    memset(p, 0, sizeof(p)); }
template <typename typ>
void memclr(typ arr[], int n) {
    memset(arr, 0, sizeof(arr[0]) * (n + 1)); }
template <typename typ, int dim>
void memclr(typ arr[][dim], int n, int m) {
    rep(i, 0, n) memset(arr[i], 0, sizeof(arr[i][0]) * (m + 1)); }

lli read(void)
{
    lli res = 0, sgn = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        sgn = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();
    return res * sgn;
}

const int maxn = 100100;
const lli modr = 1000000007;

int n;
char str[maxn];
lli dp[maxn];

int main(int argc, char** argv)
{
    scanf("%s", str + 1);
    n = strlen(str + 1);
    bool flag = false;
    dp[0] = 1;
    dp[1] = 1;
    if (str[1] == 'w' || str[1] == 'm')
        flag = true;
    rep(i, 2, n) {
        dp[i] = dp[i - 1];
        if (str[i] == 'u' && str[i - 1] == 'u')
            dp[i] += dp[i - 2];
        else if (str[i] == 'n' && str[i - 1] == 'n')
            dp[i] += dp[i - 2];
        else if (str[i] == 'w' || str[i] == 'm')
            flag = true;
        dp[i] %= modr;
    }
    if (flag)
        dp[n] = 0;
    printf("%lld\n", dp[n]);
    return 0;
}
