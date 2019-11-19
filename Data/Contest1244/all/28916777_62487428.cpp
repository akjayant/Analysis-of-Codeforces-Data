#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
long long mod=1e9+7;
long long INF=1e7;
double EPS = 1e-12;
typedef long long int lld;
double tick(){static clock_t oldt;clock_t newt=clock();
    double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt = newt;return diff;}
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%d",&a)
#define scd2(a,b) scanf("%d%d",&a,&b)
#define scd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scf(a) scanf("%lf",&a)
#define scf2(a,b) scanf("%lf%lf",&a,&b)
#define scf3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())
#define Error(x) cout<< #x << " = " << (x) <<endl;
#define Error2(a,b) cout<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define Error3(a,b,c) cout<<"("<<#a<<" , "<<#b<<" , "<<#c<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<")\n";
#define Error4(a,b,c,d) cout<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" ) = \
( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<")\n";
#define errop(a) cout<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define mset(a, v) memset(a, v, sizeof(a))
#define popcount __builtin_popcountll

typedef pair<lld,lld> PA;
 
lld powP(lld a,lld b){
    if(b==0) return 1%mod;
    lld k;
    k=powP(a,b/2);
    k=k*k%mod;
    if(b%2==0) return k;
    else return a*k%mod;
}
 
bool bitSet(lld n,lld i){
    if((n&(1LL<<i))!=0) return true;
    else return false;
}
 
lld findGcd(lld a,lld b){
    if(a==0) return b;
    else return findGcd(b%a,a);
}
 
#define lim 300010
#define lim2 200010
#define qqqqqq 210
// Ab :)
// inline lld sqr(lld x) { return x * x; }
// unordered_map<lld,lld>::iterator it;
// std::ios::sync_with_stdio(false);
// priority_queue<PA> Q;
// lld dp[1<<18];

vector<lld> G[lim];
// string S[lim];
lld A[lim],B[lim],C[lim][4], FinalColor[lim];
// map<lld,lld> M;

lld findAns(lld x, lld par, lld colPar, lld col) {
    for(auto c : G[x]) {
        if(c != par) {
            lld k = 6 - colPar - col;
            return C[c][k] + findAns(c, x, col, k);
        }
    }
    return 0;
}

void construct(lld x, lld par, lld colPar, lld col) {
    FinalColor[x] = col;
    for(auto c : G[x]) {
        if(c != par) {
            lld k = 6 - colPar - col;
            construct(c, x, col, k);
        }
    }
}

int main(){
    lld T,i,p,j,l,n,e,r,b,c,k,m,q,a,d,w,x,y,u,v,z,t,curr,prev,sum,ans,pos,val,countA,indicator;
    sc(n);
    rep(j,1,3) rep(i,1,n) sc(C[i][j]);
    rep(i,1,n-1) {
        sc2(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    lld leaf = -1;
    rep(i,1,n) {
        if(sz(G[i]) > 2) {
            printf("-1\n");
            return 0;
        }
        if(sz(G[i]) == 1) leaf = i;
    }
    ans = LLONG_MAX;
    lld colx = -1, coly = -1;
    rep(i,1,3) rep(j,1,3) {
        if(i == j) continue;
        val = C[leaf][i] + C[G[leaf][0]][j] + findAns(G[leaf][0], leaf, i, j);
        if(val < ans) {
            ans = val;
            colx = i;
            coly = j;
        }
    }
    FinalColor[leaf] = colx;
    construct(G[leaf][0], leaf, colx, coly);
    prL(ans);
    rep(i,1,n) prS(FinalColor[i]);
    return 0;
}