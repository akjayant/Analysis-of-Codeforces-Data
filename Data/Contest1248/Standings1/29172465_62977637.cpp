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
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define LL long long 
#define D double
#define sz(X) (int)(X.size())
#define itr iterator
#define mkp make_pair
#define pr pair
#define fi first
#define se second
const LL md=1004535809;
inline LL fmul(LL x,LL y,const LL P){
    /*LL res=0;
    while(y){
        if(y&1)res+=x,res%=P;
        x+=x;x%=P;y>>=1;
    }
    return res;*/
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
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
const int N=1e5+10;
int n,a[2],b[2],m;
int main(){
    int T;read(T);
    while(T--){
        a[0]=a[1]=b[0]=b[1]=0;
        read(n);int i;rep(i,1,n){
            int x;read(x);a[x&1]++;
        }
        read(m);
        rep(i,1,m){
            int x;read(x);b[x&1]++;
        }
        printf("%lld\n",(LL)a[0]*(LL)b[0]+(LL)a[1]*(LL)b[1]);
    }
}