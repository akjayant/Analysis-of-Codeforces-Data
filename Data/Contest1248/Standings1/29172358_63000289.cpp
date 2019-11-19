#include<bits/stdc++.h>

const int Mx=505;
int n,sum[Mx],mnl[Mx],mnr[Mx],ans,ll,rr;
char ch[Mx];
int ck(){
    std::memset(sum,0,sizeof sum);
    for(register int i=1;i<=n;i++){
        if(ch[i]=='(')sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }
    for(register int i=1;i<=n;i++)mnl[i]=std::min(mnl[i-1],sum[i]);
    for(register int i=n;i>=1;i--)mnr[i]=std::min(mnr[i+1],sum[i]);
    int res=0,flag=0;
    for(register int i=1;i<=n;i++)if(sum[i]<0)flag=1;
    for(register int i=1;i<n;i++){
        if(mnr[i+1]-sum[i]<0)continue;
        if(mnl[i]-sum[i]<0)continue;
        res++;
    }
    return res+1-flag;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin>>n;
    int sl=0,sr=0;
    for(int i=1;i<=n;i++){
        std::cin>>ch[i];
        if(ch[i]=='(')sl++;
        if(ch[i]==')')sr++;
    }
    if(sl!=sr){
        std::cout<<0<<std::endl<<1<<' '<<1;
        return 0;
    }
    mnl[0]=mnr[n+1]=n+1;
    ans=ck();ll=1,rr=1;
    for(register int l=1;l<n;l++){
        for(register int r=l+1;r<=n;r++){
            std::swap(ch[l],ch[r]);
            int res=ck();
            if(res>ans)ll=l,rr=r,ans=res;
            std::swap(ch[l],ch[r]);
        }
    }
    std::cout<<ans<<std::endl<<ll<<' '<<rr;
}