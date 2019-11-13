#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int exp(int a, int x){
    if (x == 0) return 1;
    int p = exp(a,x/2);
    p *= p;
    p %= mod;
    if (x % 2 == 1){
        p *= a;
        p %= mod;
    }
    //printf("%lld %lld %lld\n",a,x,p);
    return p;
}
main(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    int cur = exp(2,m)-1;
    //printf("%lld\n",cur);
    cur = exp(cur,n);
    printf("%lld ",cur);

}
