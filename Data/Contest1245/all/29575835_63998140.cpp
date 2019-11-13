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
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int A, B;
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &A, &B);
        if(gcd(A, B) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}
