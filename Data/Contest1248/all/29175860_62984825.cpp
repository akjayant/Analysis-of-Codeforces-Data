#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int a[maxn];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    ll sum1 = 0;
    for(int i = n;  i >= n  / 2 + 1; --i){
        sum1 += a[i];
    }
    ll sum2 = 0;
    for(int i = n / 2; i >= 1; --i){
        sum2 += a[i];
    }
    ll ans = sum1 * sum1 + sum2 * sum2;
    printf("%lld\n", ans);
    return 0;
}