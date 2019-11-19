#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

P a[100005],b[100005];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
        b[i].first=a[i].second;
        b[i].second=a[i].first;
    }
    sort(a+1,a+k+1);
    sort(b+1,b+k+1);
    int dir=0,flag=0,ln=1,rn=n+1,lm=0,rm=m+1;
    P p,last;
    p.first=1;
    p.second=1;
    ll ans=0;
    int T=3;
    while(1){
        last=p;
        if(dir==0){
            int pos=upper_bound(a+1,a+1+k,p)-a;
            P pp=a[pos];
            pp.second=min(pp.second,rm);
            if(pp.first==p.first){
                ans+=1ll*(pp.second-p.second-1);
                p.second=pp.second-1;
            }
            else{
                ans+=1ll*(rm-1-p.second);
                p.second=rm-1;
            }
            rm=min(rm,p.second);
            dir=(dir+1)%4;
        }
        else if(dir==2){
            int pos=upper_bound(a+1,a+1+k,p)-a;
            pos--;
            P pp=a[pos];
            pp.second=max(pp.second,lm);
            if(pos>0&&pp.first==p.first){
                ans+=1ll*(p.second-pp.second-1);
                p.second=pp.second+1;
            }
            else{
                ans+=1ll*(p.second-1-lm);
                p.second=lm+1;
            }
            lm=max(lm,p.second);
            dir=(dir+1)%4;
        }
        else if(dir==1){
            P t;
            t.first=p.second,t.second=p.first;
            int pos=upper_bound(b+1,b+1+k,t)-b;
            P pp=b[pos];
            pp.second=min(pp.second,rn);
            if(pp.first==p.second){
                ans+=1ll*(pp.second-p.first-1);
                p.first=pp.second-1;
            }
            else{
                ans+=1ll*(rn-1-p.first);
                p.first=rn-1;
            }
            rn=min(rn,p.first);
            dir=(dir+1)%4;
        }
        else if(dir==3){
            P t;
            t.first=p.second,t.second=p.first;
            int pos=upper_bound(b+1,b+1+k,t)-b;
            pos--;
            P pp=b[pos];
            pp.second=max(pp.second,ln);
            if(pos>0&&pp.first==p.second){
                ans+=1ll*(p.first-pp.second-1);
                p.first=pp.second+1;
            }
            else{
                ans+=1ll*(p.first-1-ln);
                p.first=1+ln;
            }
            ln=max(ln,p.first);
            dir=(dir+1)%4;
        }
        if(last==p) flag++;
        else flag=1;
        if(flag==2) break;
    }
    ll sum=1ll*n*m-1ll*k;
    if(sum==ans+1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
