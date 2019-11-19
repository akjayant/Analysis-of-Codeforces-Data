#include<bits/stdc++.h>
#define int unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=2e3+28;
struct E{
    int x,y,w;
    E(int X=0,int Y=0,int W=0){x=X,y=Y,w=W;}
    friend bool operator < (E a,E b){return a.w<b.w;}
}l[N*N+N];
int tot;
int n,x[N],y[N],c[N],k[N],fa[N];
queue<int>ans1;
queue<pii >ans2;
int GetFa(int x){return x==fa[x]?x:fa[x]=GetFa(fa[x]);}
int Kruskal(){
    int re=0;
    for(int i=0;i<=n;i++)fa[i]=i;
    sort(l+1,l+tot+1);
    for(int i=1;i<=tot;i++){
        int x=l[i].x,y=l[i].y,w=l[i].w;
        int fx=GetFa(x),fy=GetFa(y);
        if(fx==fy)continue;
        fa[fx]=fy;
        re+=w;
        if(x==0)ans1.push(y);
        else ans2.push(mp(x,y));
    }
    return re;
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    for(int i=1;i<=n;i++){
        c[i]=read();
        l[++tot]=E(0,i,c[i]);
    }
    for(int i=1;i<=n;i++)k[i]=read();
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=max(x[i],x[j])+max(y[i],y[j])-min(x[i],x[j])-min(y[i],y[j]);
            tmp=tmp*(k[i]+k[j]);
            l[++tot]=E(i,j,tmp);
        }
    }
    cout<<Kruskal()<<endl;
    cout<<ans1.size()<<endl;
    while(ans1.size()){
        cout<<ans1.front()<<" ";
        ans1.pop();
    }
    cout<<endl<<ans2.size()<<endl;
    while(ans2.size()){
        cout<<ans2.front().fi<<" "<<ans2.front().se<<endl;
        ans2.pop();
    }
    return 0;
}
