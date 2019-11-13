#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MOD=1e9+7;
const ll INF=1e18;
ll t,n,a[MAXN];
bool cmp(ll l1,ll l2){
    return l1>l2;
}
void solve(){
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;i++){
        if(a[i]<i){
            printf("%lld\n",i-1);
            return;
        }
    }
    printf("%lld\n",n);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        solve();
    }
}