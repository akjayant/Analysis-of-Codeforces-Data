#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
int a[N];

void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int ans = 0;
    for(int i=n;i>=1;i--){
        if(ans+1 > a[i]) break;
        else ans++;
    }
    printf("%d\n",ans);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}