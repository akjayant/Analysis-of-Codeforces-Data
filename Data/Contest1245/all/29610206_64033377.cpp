/**
* Author : Xiuchen
* Date : 2019-11-01-23.44.17
* Description : 597 Div2 D
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2100;
const ll inf=0x3f3f3f3f;
ll graph[maxn][maxn];
int n;
ll k[maxn],c[maxn];
struct node{
    ll x,y;
}a[maxn];
ll fun(int i,int j){
    ll ans;
    ans=(k[i]+k[j])*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
    return ans;
}
struct edge{
    int u,v;
};
vector<int> ans1;
vector<edge> ans2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[j][i]=graph[i][j]=fun(i,j);
            //printf("i,j:%d %d %lld\n",i,j,graph[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        graph[0][i]=graph[i][0]=c[i];
    }
    ll dis[maxn],sum=0,flag[maxn],pre[maxn];
    for(int i=1;i<=n;i++){
        dis[i]=graph[0][i];
        pre[i]=0;
        flag[i]=0;
    }
    dis[0]=0;flag[0]=1;
    for(int i=1;i<=n;i++){
        ll minn=inf,id=-1;
        for(int j=0;j<=n;j++){
            if(flag[j]) continue;
            if(dis[j]<minn){
                minn=dis[j];
                id=j;
            }
        }
        //printf("id:%d\n",id);
        sum+=minn;
        if(pre[id]==0){
            ans1.push_back(id);
            flag[id]=1;
        }
        else{
            ans2.push_back({pre[id],id});
            flag[id]=1;
        }
        for(int j=0;j<=n;j++){
            if(!flag[j]){
                if(dis[j]>graph[id][j]){
                    dis[j]=graph[id][j];
                    pre[j]=id;
                }
                //printf("j:%d %lld\n",j,dis[j]);
            }
        }
        //printf("sum:%lld\n",sum);
    }
    printf("%lld\n",sum);
    printf("%d\n",ans1.size());
    for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
    printf("\n");
    printf("%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++) printf("%d %d\n",ans2[i].u,ans2[i].v);
    return 0;
}
