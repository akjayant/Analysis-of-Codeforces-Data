#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define maxm 1006
#define ll long long int
#define INF 0x3f3f3f3f
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
#define mem(a) memset(a,0,sizeof(a))
#define sqr(x) (x*x)
#define inf (ll)2e18+1
#define PI acos(-1)
#define mod 1000000007
#define auto(i,x) for(int i=head[x];i;i=ed[i].nxt)
ll read(){
    ll x=0,f=1ll;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
     while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
     return f*x;
}
int n,s;
int a[maxn][2],k[maxn],c[maxn];
struct node{
    int u,v;ll w;
    bool operator < (const node &rid)const{
        return w > rid.w;
    }
};
priority_queue<node>q;
int king[maxn];
int getfa(int x){return king[x]==x?x:king[x]=getfa(king[x]); }
vector<int>v;
vector<pair<int,int> >vv;
int main()
{
    n=read();s=n+1;
    inc(i,1,n){a[i][0]=read();a[i][1]=read(); }
    inc(i,1,n)c[i]=read();
    inc(i,1,n)k[i]=read();
    inc(i,1,n)inc(j,1,i-1){
        ll cost=1ll*(abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))*(k[i]+k[j]);
        q.push({i,j,cost});
    }
    inc(i,1,n)q.push({s,i,c[i]});
    inc(i,1,s)king[i]=i;
    //printf("---\n");
    int cnt=0;
    ll ans=0;
    while(cnt<n){
        node now=q.top();q.pop();
        int x=now.u;
        int y=now.v;
        int tx=getfa(x);
        int ty=getfa(y);
        if(tx!=ty){
            cnt++;
            ans+=now.w;
            if(x==s||y==s){
                if(x==s)v.push_back(y);
                else v.push_back(x);
            }
            else {
                vv.push_back(make_pair(x,y));
            }
            king[tx]=ty;
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    printf("%d\n",vv.size());
    for(int i=0;i<vv.size();i++)printf("%d %d\n",vv[i].first,vv[i].second);
    return 0;
}
 