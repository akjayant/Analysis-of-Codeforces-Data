#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,m,odd1,odd2,ev1,ev2;
void solve(){
    odd1=odd2=ev1=ev2=0;
    scanf("%d",&n);
    rep(i,1,n){
        int x;scanf("%d",&x);
        if(x%2) odd1++;
        else ev1++;
    }
    scanf("%d",&m);
    rep(i,1,m){
        int x;scanf("%d",&x);
        if(x%2) odd2++;
        else ev2++;
    }
    printf("%lld\n",1ll*odd1*odd2+1ll*ev1*ev2);
}
int main(){
    int T;cin>>T;
    while(T--) solve();
}