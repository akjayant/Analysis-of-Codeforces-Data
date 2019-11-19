#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n;
long long k, a[maxn], cnt, val[maxn], num[maxn];

int main()
{
    scanf("%d%lld", &n, &k);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++) {
        if(a[i]!=a[i-1]) {
            val[++cnt] = a[i];
        }
        num[cnt]++;
    }
    int L=1, R=cnt;
    if(L==R){
        printf("0\n");
        return 0;
    }
    long long Lnum=num[L], Rnum=num[R];
    while(L<R && k){//printf("%d %d %lld\n", L, R, k);
        if(Lnum<Rnum) {
            if(k<Lnum * (val[L+1]-val[L])){
                printf("%lld\n", val[R]-val[L] - k/Lnum);
                break;
            }   else {
                k -= Lnum * (val[L+1]-val[L]);
                L++;
                Lnum += num[L];
            }

        }   else {
            if(k< Rnum * (val[R]-val[R-1])){
                printf("%lld\n", val[R]-val[L] - k/Rnum);
                break;
            }   else {
                k -= Rnum * (val[R]-val[R-1]);
                R--;
                Rnum += num[R];
            }
        }
        if(L==R) printf("0\n");
    }
    return 0;
}
