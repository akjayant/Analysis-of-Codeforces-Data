#include <iostream>
#include <stdio.h>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)

const int maxN = 1e5 + 123;
const LL MOD = 1e9 + 7;

LL M,N;

LL cal(LL x,LL y){
    if(y == 0) return 1;
    if(y == 1) return x;
    LL a = cal(x,y/2);
    a = (a * a) % MOD;
    return y % 2 == 0 ? a : (a * x) % MOD;
}
int main(){
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    cin >> N >> M;

    LL rr = cal(cal(2,M) - 1,N);

    rr %= MOD;
    if(rr < 0) rr += MOD;

    cout << rr;


    return 0;
}