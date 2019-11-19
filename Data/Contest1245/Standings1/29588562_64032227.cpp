#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
#define fi first
#define se second
#define pb push_back
int n;
struct uzi{
    LL x,y;
}p[N];
LL c[N],k[N];
LL dis[2222][2222];
struct faker{
    LL a,b;
    LL w;
    bool operator <(const faker &t)const{
        return w<t.w;
    }
}Q[N];
int cnt;
int f[N];
int find(int x){ return f[x]==x?x:(f[x]=find(f[x]));}

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;
    p[0]={0,0};
    for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>k[i];
    for(int i=1;i<=n;i++){
        Q[++cnt]={0,i,c[i]};
        for(int j=i;j<=n;j++){
            dis[i][j]=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
            dis[i][j]*=k[i]+k[j];
            Q[++cnt]={i,j,dis[i][j]};
        }
    }
    vector<int>tmp;
    vector<pair<int,int> >ed;
    sort(Q+1,Q+1+cnt);
    LL tot=0;
    int ppt=0;
    for(int i=1;i<=cnt;i++){
        int x=find(Q[i].a);
        int y=find(Q[i].b);
        if(x==y)continue;
        if(!Q[i].a){
            f[y]=x;
            tmp.pb(Q[i].b);
        }else if(!Q[i].b){
            f[x]=y;
            tmp.pb(Q[i].a);
        }else{
            f[x]=y;
            ed.pb({Q[i].a,Q[i].b});
        }
        tot+=Q[i].w;
        if(++ppt==n)break;
    }
    cout<<tot<<'\n';
    cout<<(int)tmp.size()<<'\n';
    for(auto k:tmp)cout<<k<<' ';
    cout<<'\n';
    cout<<(int)ed.size()<<'\n';
    for(auto k:ed){
        cout<<k.fi<<' '<<k.se<<'\n';
    }
    return 0;
}