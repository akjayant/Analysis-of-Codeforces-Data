#include<bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define _end printf("\n")
#define dg(x) cout << #x << '=' << x << ' '
#define mem(a, b) memset(a, b, sizeof(a))

void _in(long long *a, ...){

    va_list arg_ptr;

    scanf("%I64d", a);
    long long *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, long long*);

    while(temp){
        scanf("%I64d", temp);
        temp = va_arg(arg_ptr, long long*);
    }

    va_end(arg_ptr);
}

void _in(int *a, ...){
    va_list arg_ptr;

    scanf("%d", a);
    int *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, int*);
    while(temp){
        scanf("%d", temp);
        temp = va_arg(arg_ptr, int*);
    }

    va_end(arg_ptr);
}

#define in(...) _in(__VA_ARGS__, 0)
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
const ll NN = 1e5;
ll fact[N], invfac[N];
char a[N];

void exgcd(ll b, ll p, ll & a, ll & k) {
    if(p == 0) {
        a = 1; k = 0;
        return;
    }
    exgcd(p, b % p, k, a);
    k -= b / p * a;
    return;
}

ll inv(ll b, ll p) {
    ll a, k;
    exgcd( b, p, a, k );
    if(a < 0) a += p;
    return a;
}

ll C(ll n, ll m){
    ll ret = fact[n] * invfac[n - m];
    ret %= MOD;
    ret *= invfac[m];
    return ret % MOD;
}

ll poss(ll n){
    ll nn, mn, res;
    nn = n; mn = 0;
    res = 1;
    while(nn >= 2){
        nn -= 2;
        mn += 1;
        res += C(nn + mn, mn);
        res %= MOD;
    }
    return res;
}

void init(ll n) {
    fact[0] = 1;
    for(ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invfac[n] = inv(fact[ n ], MOD);
    for(ll i = n - 1; i >= 0; --i) invfac[i] = invfac[i + 1] * (i + 1) % MOD;
}

int main(){

    char t;
    int p = 0;
    while(scanf("%c", &t) != -1){
        a[++p] = t;
        if(t == 'm' || t == 'w'){
            printf("0");
            return 0;
        }
    }
    init(p);
    ll ans = 1, unum = 0, nnum = 0;
    a[p + 1] = ' ';
    repi(i, 1, p + 1){
        if(a[i] == 'u' && !nnum) unum++;
        else if(a[i] == 'n' && !unum) nnum++;
        else{
            ans *= poss(unum);
            ans %= MOD;
            ans *= poss(nnum);
            ans %= MOD;
            nnum = 0;
            unum = 0;
            if(a[i] == 'n') nnum++;
            if(a[i] == 'u') unum++;
        }
    }
    printf("%I64d", ans);

    return 0;
}