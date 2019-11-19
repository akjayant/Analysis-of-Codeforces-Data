/*
恍若
韶华辗转却在肩头搁浅
伞下方寸间
就足以勾勒尘寰穹宇楼阙
凝眸一眼
似清风在掌心盘旋
化为岚烟
盛漫天春意正酽酽
*/
#include <bits/stdc++.h>
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define LL long long
#define D double
#define sz(X) (int)(X.size())
#define itr iterator
#define mkp std::make_pair
#define pr std::pair
#define fi first
#define se second
const LL md=167772161;
inline LL fmul(LL x,LL y,const LL P){
    /*LL res=0;
    while(y){
        if(y&1)res+=x,res%=P;
        x+=x;x%=P;y>>=1;
    }
    return res;
    */
    //return (x*y-(LL)((long double)x/P*y)*P+P)%P;
    return (x*y)%P;
}
inline LL fpw(LL x,LL y,const LL modol){
    if(x==modol-1)return y&1 ? modol-1:1;
    LL res=1;while(y){if(y&1)res=fmul(res,x,modol);x=fmul(x,x,modol);y>>=1;}return res%modol;
}
LL exgcd(LL& x,LL& y,LL a,LL b){
    if(!b){x=1;y=0;return a;}
    LL res=exgcd(y,x,b,a%b);y-=x*(a/b);return res;
}
inline LL ad(LL x,LL y,const LL md){
    return x+y>=md ? x+y-md:x+y;
}
inline LL sub(LL x,LL y,const LL md){
    return x<y ? md+x-y:x-y;
}
inline LL inv(LL o,const LL modol){
    LL x,y;exgcd(x,y,o,modol);
    x=(x%modol+modol)%md;return x;
}
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
LL mmax(LL x,LL y){return x>y ? x:y;}
LL mmin(LL x,LL y){return x<y ? x:y;}
const int N=1e6+10;
LL n;
LL ans;
bool vis[N];
int prim[N];
bool isprim(LL x){
    LL i;
    for(i=2;i*i<=x;++i)if(x%i==0)return 0;
    return 1;
}
int main(){
    scanf("%I64d",&n);LL i,j;
    if(n==1){
        printf("1");return 0;
    }
    if(isprim(n)){
        printf("%I64d\n",n);return 0;
    }
    rep(i,2,N-10){
        if(!vis[i]){prim[++prim[0]]=i;}
        for(j=1;j<=prim[0] && prim[j]*i<=N-10;++j){
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
    rep(i,1,prim[0])if(n%prim[i]==0){
        while(n%prim[i]==0)n/=prim[i];
        break;
    }
    if(n!=1)printf("1");else printf("%d",prim[i]);
}