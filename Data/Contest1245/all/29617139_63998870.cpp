#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;
#define maxn 100005
#define maxm 1000005
#define ll long long
#define inf 1e9
#define eps 1e-15
#define mod 998244353
#define inv2 500000004
#define inv3 333333336
#define sc(x) scanf("%d",&x)
int t,n,m,K,d,res,ans;
int dp[maxn],w[maxn],v[maxn];
int pd(int x){
    if(x>=10000)return 5;
    else if(x>=1000)return 4;
    else if(x>=100)return 3;
    else if(x>=10)return 2;
    return 1;
}
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(){
    sc(t);
    while(t--){
        if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
if(2==3)printf("0------------\n");
        sc(n);sc(m);
        if(gcd(n,m)==1)printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}

