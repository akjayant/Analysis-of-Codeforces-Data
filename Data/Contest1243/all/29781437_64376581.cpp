#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int a[MAXN];
bool cmp(int x, int y){
    return x > y;
}
void solve(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, cmp);
    //for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    int ans = 0;
    for(int i = 1; i <= n && a[i] >= i; i++) ans = i;
    printf("%d\n", ans);
}

int main(){
    int T; scanf("%d", &T);
    while(T--) solve();
}