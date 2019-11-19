/*cout<<"─────────▄──────────────▄"<<endl;
    cout<<"────────▌▒█───────────▄▀▒▌"<<endl;
    cout<<"────────▌▒▒▀▄───────▄▀▒▒▒▐"<<endl;
    cout<<"───────▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐"<<endl;
    cout<<"─────▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐"<<endl;
    cout<<"───▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌"<<endl;
    cout<<"──▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌much speed"<<endl;
    cout<<"──▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌"<<endl;
    cout<<"─▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌"<<endl;
    cout<<"─▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐ Wow"<<endl;
    cout<<"▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌"<<endl;
    cout<<"▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐"<<endl;
    cout<<"─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌good macro"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐"<<endl;
    cout<<"──▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌"<<endl;
    cout<<"────▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀"<<endl;
    cout<<"───▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀"<<endl;
    cout<<"──▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀"<<endl;*/

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll;
const int MM = 10;
const ll INF = 1e18 ;
inline ll checjk (ll x){return x > 0 ? x : -x ;}
const int maxn = 2e3 + 10 ;
bool vvvvv[maxn] ;
ll lowc[maxn] , n ;
ll fa[maxn] , x[maxn], y[maxn] , k[maxn] , c[maxn] , cost[maxn][maxn] ;
vector <ll> V ;
vector <ll> num11111 , num22222 ;

struct Matrix {
    int mat[MM][MM];
};

Matrix multiply(Matrix a,Matrix b,int M) {
    Matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            if(a.mat[i][j]==0)continue;
            for(int k=0;k<M;k++) {
                if(b.mat[j][k]==0)continue;
                c.mat[i][k]=(c.mat[i][k]+a.mat[i][j]*b.mat[j][k])%M;
            }
        }
    }
    return c;
}

Matrix quickmod(Matrix a,int n,int M) {
    Matrix res;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++)
            res.mat[i][j]=(i==j);
    }
    while(n) {
        if(n&1) res=multiply(res,a,M);
        n>>=1;
        a=multiply(a,a,M);
    }
    return res;
}

ll solve(ll n){
    ll ans = 0 ;
    memset (vvvvv , false , sizeof (vvvvv)) ;
    vvvvv[0] = true ;
    for (ll i = 1 ; i <= n ; ++i){lowc[i] = cost[0][i] ;fa[i] = 0 ;}
    for (ll i = 1 ; i <= n ; ++i){
        ll minc = INF ;
        ll p = -1 ;
        for (ll j = 1 ; j <= n ; ++j)if (!vvvvv[j] && minc > lowc[j]){minc = lowc[j] ;p = j ;}
        if (minc == INF)return -1 ;
        ans += minc ;
        vvvvv[p] = true ;
        if (fa[p] == 0) V.push_back(p) ;
        else{num11111.push_back(p) ;num22222.push_back(fa[p]) ;}
        for (ll j = 1 ; j <= n ; ++j) if (!vvvvv[j] && lowc[j] > cost[p][j]){lowc[j] = cost[p][j] ;fa[j] = p ;}
    }
    return ans ;
}

 /*(for(int i = 0; i < n; i++){
                if(ans[i] == 1) cout<<"R";
                else if(ans[i] == 2) cout<<"P";
                else if(ans[i] == 3) cout<<"S";
                else{
                    if(a > 0) cout<<"R", a--;
                    else if(b > 0) cout<<"P", b--;
                    else if(c > 0) cout<<"S", c--;
                }
}*/

int solve1(){
    scanf ("%lld" , &n) ;
    for (ll i = 1 ; i <= n ; ++i) scanf ("%lld%lld" , &x[i] , &y[i]) ;
    for (int i = 1 ; i <= n ; ++i){scanf ("%lld" , &c[i]) ;cost[0][i] = c[i] ;}
    for (int i = 1 ; i <= n ; ++i){
        scanf ("%lld" , &k[i]) ;
        for (int j = 1 ; j < i ; ++j)cost[i][j] = cost[j][i] = (k[i] + k[j]) * (checjk(x[i] - x[j]) + checjk(y[i] - y[j])) ;
    }
    printf ("%lld\n" , solve(n)) ;
    printf ("%d\n" , V.size()) ;
    for (int i = 0 ; i < V.size() ; ++i)printf ("%lld " , V[i]) ;
    printf ("\n%d\n" , num11111.size()) ;
    for (int i = 0 ; i < num11111.size() ; ++i)printf ("%lld %lld\n" , num11111[i] , num22222[i]) ;
}

int main (){
    solve1();
    return 0 ;
}
