#include <cstdio>


using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 100005;

int f[MAXN];

int MUL(ll a, ll b){
    return a*b%MOD;
}
int ADD(ll a, ll b){
    return (a+b)%MOD;
}
int EXP(ll b, int e){
    if(e==0) return 1;
    if(e%2) return MUL(b, EXP(b, e-1));
    else return EXP(MUL(b,b), e/2);
}
int DIV(ll a, ll b){
    return MUL(a, EXP(b, MOD-2));
}
int C(ll n, ll k){
    return DIV(f[n], MUL(f[n-k], f[k]));
}

int solve_row(int x){
    int res=0;
    for(int i=1;2*i<=x;++i){
        res = ADD(res, C(x-i, i));
    }
    return res;
}

int main(){
    f[0]=1;
    for(int i=1;i<MAXN;++i) f[i]=MUL(f[i-1], i);
    int n,m;
    scanf("%d%d", &n, &m);
    int sol=MUL(2, ADD(ADD(solve_row(n), solve_row(m)), 1));
    printf("%d\n", sol);
}
