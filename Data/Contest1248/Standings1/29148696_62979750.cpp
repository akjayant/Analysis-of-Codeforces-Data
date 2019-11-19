#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int main(){
    int T; scanf("%d", &T);
    while (T--){
        int n, m, x;
        long long p0, p1, q0, q1;
        p0 = p1 = q0 = q1 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
            scanf("%d", &x);
            if (x & 1) ++p1;
            else ++p0;
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i){
             scanf("%d", &x);
             if (x & 1) ++q1;
             else ++q0;
        }
        printf("%I64d\n", p0*q0 + p1*q1);
    }
    return 0;
}