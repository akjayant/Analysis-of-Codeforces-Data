#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1e4+10;
pii pos[N]; 
ll c[N],k[N],vis[N],cnt;

struct node{
    ll type,val,id;    // 0: 建厂, !0:建路
    bool operator <(const node oth)const {
        if(val == oth.val) return type > oth.type;
        return val > oth.val;
    }
};
vector<pii> road;
vector<int> chang;
int dis(int i,int j){
    return abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
}
int main(){
    priority_queue<node> que;
    int n;
    ll ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&pos[i].first,&pos[i].second);
    }
    for(int i=1;i<=n;++i)   scanf("%d",&k[i]);
    for(int i=1;i<=n;++i)   scanf("%d",&c[i]),que.push((node){0,k[i],i});
    while(cnt<n && que.size()){
        node tp = que.top();    que.pop();
        if(vis[tp.id])  continue;
        ans+=tp.val;    vis[tp.id] = 1;
        if(tp.type==0){
            chang.push_back(tp.id);
        }else{
            road.push_back((pii){tp.id,tp.type});   
        }
        for(int i=1;i<=n;++i){
            ll val = dis(i,tp.id);
            if(!vis[i] && val<=k[i])
                que.push((node){tp.id,val*1LL*(c[i]+c[tp.id]),i});
        }
    }
    printf("%lld\n%d\n",ans,chang.size());
    for(auto ch:chang){
        printf("%d ",ch);
    }
    printf("\n%d\n",road.size());
    for(auto ro:road){
        printf("%d %d\n",ro.first,ro.second);
    }

    return 0;
}