#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            if(x & 1) ++cnt1;
            else ++cnt2;
        }
        scanf("%d", &m);
        int cnt3 = 0, cnt4 = 0;
        for(int i = 1; i <= m; ++i){
            int x;
            scanf("%d", &x);
            if(x & 1) ++cnt3;
            else ++cnt4;
        }
        ll ans = (ll)cnt1 * cnt3 + (ll)cnt2 * cnt4;
        printf("%lld\n", ans);
    }
    return 0;
}