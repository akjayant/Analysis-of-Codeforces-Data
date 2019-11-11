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
int N, A, B, C;
char op[105], ans[105];
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        memset(ans, 0, sizeof(ans));
        scanf("%d%d%d", &A, &B, &C);    //A rock, B paper, C s
        scanf("%s", op + 1);
        int win = 0;
        for(int i=1; i<=N; i++)
        {
            if(op[i] == 'R')
            {
                if(B)
                {
                    win++;
                    B--;
                    ans[i] = 'P';
                }
            }
            else if(op[i] == 'S')
            {
                if(A)
                {
                    win++;
                    A--;
                    ans[i] = 'R';
                }
            }
            else
            {
                if(C)
                {
                    win++;
                    C--;
                    ans[i] = 'S';
                }
            }
        }
        if(win < (N + 1) / 2) { printf("NO\n"); continue; }
        for(int i=1; i<=N; i++)
        {
            if(ans[i]) continue;
            if(A) { A--; ans[i] = 'R'; }
            else if(B) { B--; ans[i] = 'P'; }
            else { C--; ans[i] = 'S'; }
        }
        printf("YES\n");
        for(int i=1; i<=N; i++) printf("%c", ans[i]);
        puts("");
    }
    return 0;
}
