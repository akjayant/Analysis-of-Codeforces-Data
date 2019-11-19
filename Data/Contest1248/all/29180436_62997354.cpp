#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;

LL memo[100005][3][2];

LL solve(int ix, int sisa, bool con){
    if(ix<=0){
        return 1;
    }
    if(memo[ix][sisa][con]!=-1) return memo[ix][sisa][con];
    LL ret=0;
    if(sisa==2){
        ret+=solve(ix-1, 1, con^1);
        ret%=MOD;
    }
    else{
        ret+=solve(ix-1, sisa+1, con);
        ret%=MOD;
        ret+=solve(ix-1, 1, con^1);
        ret%=MOD;
    }
    return memo[ix][sisa][con]=ret;
}

int main(){
    memset(memo, -1, sizeof(memo));
    int n, m;
    cin>>n>>m;
    LL hasil=(solve(n-1, 1, 1)+solve(n-1, 1, 0))%MOD+(solve(m-1,1,1)+solve(m-1,1,0))%MOD;
    cout<<((hasil-2)%MOD+MOD)%MOD<<endl;
    return 0;
}