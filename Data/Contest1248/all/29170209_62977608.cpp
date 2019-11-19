#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 2e6+5;
const ll mod = 1e9+7;



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        int a[] = {0,0};
        int b[] = {0,0};
        scanf("%d", &n);
        for(int i = 1, x; i <= n; i++){
            scanf("%d", &x);
            a[x%2]++;
        }
        scanf("%d", &m);
        for(int i = 1, x; i <= m; i++){
            scanf("%d", &x);
            b[x%2]++;
        }
        printf("%lld\n", 1ll*a[0]*b[0]+1ll*a[1]*b[1]);
    }

    return 0;
}
