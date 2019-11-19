/**
 *     author:     TelmaZzzz
 *     create:     2019-11-01-22.29.46
**/
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(db &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const db &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define erp(x,y,z) for(int x=y;x>=z;x--)
#define PB push_back
#define MP make_pair
#define INF 1073741824
#define inf 1152921504606846976
#define pi 3.14159265358979323846
#define Fi first
#define Se second
//#pragma comment(linker,"/STACK:10240000,10240000")
//mt19937 rand_(time(0));
const int N=3e5+7,M=2e6;
const long long mod=1e9+7;
inline int read(){int ret=0;char ch=getchar();bool f=1;for(;!isdigit(ch);ch=getchar()) f^=!(ch^'-');for(;isdigit(ch);ch=getchar()) ret=(ret<<1)+(ret<<3)+ch-48;return f?ret:-ret;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}//逆元
//int head[N],NEXT[M],ver[M],tot;void link(int u,int v){ver[++tot]=v;NEXT[tot]=head[u];head[u]=tot;}
void TelmaZzzz(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
}


ll dp[36][36][36][2][2][2][2];
int a[42];
int b[42];
ll dfs(int pos,int up1,int num1,int zero1,int up2,int num2,int zero2){
    if(dp[pos][num1][num2][zero1][zero2][up1][up2]!=-1) return dp[pos][num1][num2][zero1][zero2][up1][up2];

    ll res=0;
    if(pos==1) return 1;
    if(up1){
        if(up2){
            if(a[pos-1]==1){
                if(b[pos-1]==1){
                    res+=dfs(pos-1,0,num1,zero1,0,num2,zero2);
                    res+=dfs(pos-1,0,num1,zero1,1,num2+1,max(zero2,1));
                    res+=dfs(pos-1,1,num1+1,max(1,zero1),0,num2,zero2);
                }
                else {
                    res+=dfs(pos-1,0,num1,zero1,1,num2,zero2);
                    res+=dfs(pos-1,1,num1+1,max(1,zero1),1,num2,zero2);
                }
            }
            else {
                if(b[pos-1]==1){
                    res+=dfs(pos-1,1,num1,zero1,0,num2,zero2);
                    res+=dfs(pos-1,1,num1,zero1,1,num2+1,max(zero2,1));
                    //res+=dfs(pos-1,1,num1+1,max(1,zero1),0,num2,zero2);
                }
                else {
                    res+=dfs(pos-1,1,num1,zero1,1,num2,zero2);
                    //res+=dfs(pos-1,0,num1,zero1,1,num2+1,max(zero2,1));
                    //res+=dfs(pos-1,1,num1+1,max(1,zero1),0,num2,zero2);
                }
            }
        }
        else {
            if(a[pos-1]==1){
                res+=dfs(pos-1,0,num1,zero1,0,num2,zero2);
                res+=dfs(pos-1,0,num1,zero1,0,num2+1,zero2);
                res+=dfs(pos-1,1,num1+1,max(1,zero1),0,num2,zero2);
            }
            else {
                res+=dfs(pos-1,1,num1,zero1,0,num2,zero2);
                res+=dfs(pos-1,1,num1,zero1,0,num2+1,zero2);
                //res+=dfs(pos-1,1,num1+1,max(1,zero1),0,num2,zero2);
            }
        }
    }
    else {
        if(up2){
            if(b[pos-1]==1){
                res+=dfs(pos-1,0,num1,zero1,0,num2,zero2);
                res+=dfs(pos-1,0,num1,zero1,1,num2+1,max(1,zero2));
                res+=dfs(pos-1,0,num1+1,zero1,0,num2,zero2);
            }
            else {
                res+=dfs(pos-1,0,num1,zero1,1,num2,zero2);
                res+=dfs(pos-1,0,num1+1,zero1,1,num2,zero2);
            }
        }
        else {
            res+=dfs(pos-1,0,num1,zero1,0,num2,zero2);
            res+=dfs(pos-1,0,num1+1,zero1,0,num2,zero2);
            res+=dfs(pos-1,0,num1,zero1,0,num2+1,zero2);
        }
    }
    return dp[pos][num1][num2][zero1][zero2][up1][up2]=res;
}
ll solve(ll x,ll y){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=34;i++){
        a[i]=x%2;
        x/=2;
    }
    for(int i=1;i<=34;i++){
        b[i]=y%2;
        y/=2;
    }
    return dfs(35,1,0,0,1,0,0);
}
int main(){
    TelmaZzzz();
    //ios::sync_with_stdio(false);
    int t;
    R(t);
    ll l,r;
    //cout<<solve(4,1)<<endl;
    while(t--){
        R(l,r);
        //cout<<solve(r,r)<<endl;
        if(l==0){
            printf("%lld\n",solve(r,r));
        }
        else
        printf("%lld\n",solve(r,r)-solve(r,l-1)*2+solve(l-1,l-1));
    }
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}


