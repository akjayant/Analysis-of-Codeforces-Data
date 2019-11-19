#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, m;
int a, b;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        long long ao = 0, ae = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            if(a & 1) ao++;
            else ae++;
        }

        scanf("%d", &m);
        long long bo = 0, be = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d", &b);
            if(b & 1) bo++;
            else be++;
        }

        printf("%lld\n", ao * bo + ae * be);

    }


    return 0;
}
