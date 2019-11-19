/// I won't go back on my words ... that's my ninja way !!!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ,mod = 1e9+7 ;
int n ,m ,mem[N] ;
int dp(int i){
    if(i>n) return 0;
    if(i==n) return 1;
    int&ret = mem[i];
    if(~ret) return ret;
    return ret = (0ll + dp(i+1) + dp(i+2))%mod ;
}
int ans[N] ,add[N] ;
int main(){
    add[1] = 2 ;
    add[2] = 2 ;
    for(int i=3;i<N;++i){
        add[i] = (0ll + add[i-1] + add[i-2])%mod ;
    }
    cin >> n >> m ;
    memset(mem,-1,sizeof mem);
    ans[1] = dp(0)*2ll %mod ;
    for(int j=2;j<=m;++j) ans[j] = (ans[j-1] + add[j-1])%mod ;
    cout << ans[m] ;
    return 0;
}
