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
const LL md=(1e9)+7;
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
const int N=5e2+10;
char s[N];
int n,mn[N],a[N];
int solve(){
    int tp=0,i;
    mn[1]=a[1];tp=a[1];
    rep(i,2,n){
        tp+=a[i];
        mn[i]=min(mn[i-1],tp);
    }
    int f,sum,res=0;
    sum=f=a[n];
    if(f>=0 && sum+mn[n-1]>=0)++res;
    dow(i,n-1,2){
        f=min(f+a[i],a[i]);sum+=a[i];
        if(f>=0 && sum+mn[i-1]>=0)++res;
    }
    sum+=a[1];
    if(sum!=0)return 0;
    tp=0;
    bool flg=1;
    rep(i,1,n){tp+=a[i];if(tp<0)flg=0;}
    return flg ? res+1:res;
}
int mv=0,al,ar;
int main(){
    scanf("%d",&n);int i,j;
    scanf("%s",s+1);
    rep(i,1,n)if(s[i]=='(')a[i]=1;else a[i]=-1;
    al=ar=1;
    rep(i,1,n)rep(j,i,n){
        swap(a[i],a[j]);int tmp=solve();
        if(tmp>mv)al=i,ar=j,mv=tmp;
        swap(a[i],a[j]);
    }
    printf("%d\n%d %d\n",mv,al,ar);
}