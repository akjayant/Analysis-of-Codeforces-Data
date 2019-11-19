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
const int N=1e5+10;
int fa[N],id[N],nxt[N],n,m;
int fd(int x){
    if(fa[x]!=x)fa[x]=fd(fa[x]);return fa[x];
}
void merg(int x,int y){
    x=fd(x);y=fd(y);if(x==y)return;
    fa[x]=y;
}
std::vector<int>tt;
int mg(int l,int r){
    int i,to;if(r>=l)tt.push_back(l);
    for(i=l+1;i<=r;i=to){
        merg(i-1,i);
        to=nxt[i];nxt[i]=nxt[r];
    }
}
std::vector<int>G[N];
int main(){
    n=read();m=read();int i,j;
    rep(i,1,n)fa[i]=i,nxt[i]=i+1;
    rep(i,1,m){
        int x=read(),y=read();
        G[x].push_back(y);G[y].push_back(x);
    }
    rep(i,1,n){
        std::sort(G[i].begin(),G[i].end());
        int sz=G[i].size();--sz;
        if(sz>=0){
            tt.clear();
            mg(1,G[i][0]-1);int pre=G[i][0]+1;
            rep(j,1,sz)mg(pre,G[i][j]-1),pre=G[i][j]+1;
            mg(pre,n);
            sz=tt.size()-1;
            rep(j,1,sz)merg(tt[j-1],tt[j]);
        }else{
            printf("0\n");return 0;
        }
    }
    int ans=0;
    rep(i,1,n)if(fa[i]==i)++ans;
    std::cout<<ans-1;
}
