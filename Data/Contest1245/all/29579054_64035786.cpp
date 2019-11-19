#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2000+7;
const int mod=1e9+7;
ll ans=0;
int boss[maxn],c[maxn],k[maxn];
int light[maxn],cnt;
pii a[maxn];
vector<int>ans1;
vector<pii>ans2;
int fin(int x){
    if(boss[x]==x)return x;
    return boss[x]=fin(boss[x]);
}
struct Node{
    ll cost;
    int cmd,x,y;
    bool operator< (const Node &a)const{
        if(cost==a.cost)return cmd<a.cmd;
        return cost<a.cost;
    }
}node[4002007];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].first,&a[i].second),boss[i]=i;
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),node[++cnt]={c[i],0,i,0};
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=abs(a[i].first-a[j].first);
            int y=abs(a[i].second-a[j].second);
            node[++cnt]={(ll)(x+y)*(k[i]+k[j]),1,i,j};
        }
    }
    sort(node+1,node+1+cnt);
    int res=0;
    for(int i=1;i<=cnt;i++){
        Node now=node[i];
       // cout<<now.cost<<" "<<now.cmd<<" "<<now.x<<" "<<now.y<<endl;
        if(now.cmd==0&&light[fin(now.x)]==0){
            ans+=now.cost;
            light[fin(now.x)]=1;
            res++;
            ans1.push_back(now.x);
        }else if(now.cmd==1){
            int a=fin(now.x),b=fin(now.y);
            if(a==b||(light[a]&&light[b]))continue;
            else {
                ans+=now.cost;
                boss[a]=boss[b];
                if(light[a])light[b]=1;
                res++;
                ans2.push_back({now.x,now.y});
            }
        }
        if(res>=n)break;
    }
    printf("%lld\n",ans);
    printf("%d\n",ans1.size());
    for(int i=0;i<ans1.size();i++)
        printf("%d%c",ans1[i]," \n"[i==ans1.size()-1]);
    printf("%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++)
        printf("%d %d%c",ans2[i].first,ans2[i].second," \n"[1]);
    return 0;
}
