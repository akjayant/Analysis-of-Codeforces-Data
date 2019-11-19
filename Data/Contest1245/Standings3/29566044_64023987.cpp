#include<bits/stdc++.h>
#define st first
#define nd second
using  namespace std;
typedef  long long ll;
typedef  pair<int,int> pii;
pii nodePos[2005];
pair<ll,int> prim[2005];
ll cost[2005];
bool ch[2005];
vector<int> v;
vector<pii> co;
int main(){
    int n,pos;
    ll sum = 0,mi,val;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&nodePos[i].st,&nodePos[i].nd);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&prim[i].st),prim[i].nd=0;
    for(int i=1;i<=n;i++) scanf("%lld",&cost[i]);
    for(int i=1;i<=n;i++){
        mi = 1e9+7,pos=-1;
        for(int j=1;j<=n;j++){
            if(!ch[j] && prim[j].st < mi){
                mi=prim[j].st;
                pos=j;
            }
        }
        //printf("mi=%lld\n",mi);
        sum+=mi;
        if(prim[pos].nd == 0){
            v.push_back(pos);
        }
        else{
            co.push_back({pos,prim[pos].nd});
        }
        ch[pos]=true;
        for(int j=1;j<=n;j++){
            if(!ch[j]){
                val = (ll)(abs(nodePos[pos].st-nodePos[j].st)+abs(nodePos[pos].nd-nodePos[j].nd))*(cost[pos]+cost[j]);
                if(prim[j].st>val){
                    prim[j].st = val;
                    prim[j].nd = pos;
                }
            }
        }

    }
    printf("%lld\n",sum);
    printf("%d\n",(int)(v.size()));
    for(auto it:v) printf("%d ",it);
    printf("\n%d\n",(int)(co.size()));
    for(auto it:co) printf("%d %d\n",it.st,it.nd);

}
