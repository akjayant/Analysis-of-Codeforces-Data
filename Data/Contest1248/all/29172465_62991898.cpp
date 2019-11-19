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
const int N=1e5+10;
const int wxy=1e5;
LL a[N];
int n,m;
int main(){
    a[1]=2;a[2]=4;
    cin>>n>>m;int i;
    rep(i,3,wxy)a[i]=ad(a[i-1],a[i-2],md);
    cout<<sub(ad(a[n],a[m],md),(LL)2,md);
}