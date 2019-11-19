#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000005;
ll dp[100005];
ll fp[100005];
ll mod = 1000000007;

void solve1(){
    fp[1] = 2;
    fp[2] = 4;
    for(int i = 3; i<=100000; i++) {
        fp[i] = fp[i-1] + fp[i-2];
        fp[i] %= mod;
    }
   
}

void solve2(){
    dp[2] = 6LL;
    dp[3] = 8LL;
    dp[4] = 12LL;
    for(int i = 5; i<=100000; i++){
        dp[i] = 2 * dp[i-1] - dp[i-3];
        while(dp[i]<0) dp[i] += mod;
        dp[i] %= mod;
    } 
}
int main() {

    #ifdef local
          freopen("in.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;

    cin>>n>>m;

    if(n>m) swap(n, m);

    if(n == 1){
        solve1();
        cout<<fp[m]<<endl;
        return 0;
    }


    solve2();
    solve1();

    ll diff = m-2;
    ll ret = dp[n];

    for(int i = 1; i<=diff; i++){
        ret += fp[i];
        ret %= mod;
    }

    ret %= mod;
    cout<<ret<<endl;





   
}
