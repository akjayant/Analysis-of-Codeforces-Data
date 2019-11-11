
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

const int maxn = 210;

int T, n, a, b, c;
char str[maxn], out[maxn];

int main(int argc, char** argv)
{
    scanf("%d", &T);
    rep(case_, 1, T) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        scanf("%s", str + 1);
        int res = 0;
        rep(i, 1, n) {
            if (str[i] == 'R' && b > 0) {
                out[i] = 'P';
                b -= 1;
                res += 1;
            } else if (str[i] == 'P' && c > 0) {
                out[i] = 'S';
                c -= 1;
                res += 1;
            } else if (str[i] == 'S' && a > 0) {
                out[i] = 'R';
                a -= 1;
                res += 1;
            } else {
                out[i] = '-';
            }
        }
        rep(i, 1, n) {
            if (out[i] != '-')
                continue;
            if (a > 0) {
                out[i] = 'R';
                a -= 1;
            } else if (b > 0) {
                out[i] = 'P';
                b -= 1;
            } else if (c > 0) {
                out[i] = 'S';
                c -= 1;
            }
        }
        if (res >= (n + 1) / 2) {
            printf("YES\n");
            rep(i, 1, n)
                printf("%c", out[i]);
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
