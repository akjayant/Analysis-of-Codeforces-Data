#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[100005];
ll k;
ll calc(int x, int d){
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] < x) res += 1ll * x - a[i];
        else if (a[i] > x + d) res += 1ll * a[i] - x - d;
    }
    return res;
}
void init(){
    scanf("%d%I64d", &n, &k);   
    for (int i = 1; i <= n;++i)
        a[i]     = read();
    sort(a + 1, a + n + 1);

}
void solve(){
    int l = 0, r = a[n] - a[1];
    while (r - l > 0){
        int mid = (l + r) >> 1;
        int l1 = a[1], r1 = a[n];
        while (r1 > l1){
            int mid1 = (l1 + r1) >> 1;
            int mid2 = (mid1 + r1 + 1) >> 1;
            if (calc(mid1, mid) > calc(mid2, mid))
                l1 = mid1 + 1;
            else r1 = mid2 - 1;
        }
        if (calc(l1, mid) > k)
            l = mid + 1;
        else r = mid;
    }
    printf("%d\n", l);
}
int main(){
    init();
    solve();
    return 0;
}