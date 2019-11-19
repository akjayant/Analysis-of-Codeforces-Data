#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MOD=1e9+7;
const ll INF=1e18;
ll n,cnt,x;
void solve(){
    ll save=n;
    for(ll i=2;i<=n/i;i++){
        ll p=0;
        while(n%i==0){
            n/=i;
            p++;
            x=i;
        }
        if(p){
            cnt++;
        }
    }
    if(n>1&&n!=save){
        cnt++;
    }
    if(!cnt){
        printf("%lld\n",n);
    }
    else{
        if(cnt>1){
            printf("1\n");
        }
        else{
            printf("%lld\n",x);
        }
    }
}
int main(){
    scanf("%lld",&n);
    solve();
}