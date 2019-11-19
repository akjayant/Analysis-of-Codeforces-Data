#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
ll c[maxn],k[maxn];
struct Point{
  ll x,y;
}a[maxn];
struct edge{
  int x,y;
  ll val;
}b[maxn*maxn];
bool cmp(edge r,edge t){
    return r.val<t.val;
}
int father[maxn];
void init(){
 for(int i=1;i<=3000;i++) father[i]=i;
}
int findfather(int x){
  if(father[x]==x) return father[x];
  return father[x]=findfather(father[x]);
}
vector<int>dian;
vector<pair<int,int>>lian;
int main() {
    int n;
    scanf("%d",&n);
    init();
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        b[cnt].x=0;
        b[cnt].y=i;
        b[cnt++].val=c[i];
    }
     for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            b[cnt].x=i;
            b[cnt].y=j;
            b[cnt++].val=(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(k[i]+k[j]);
        }
    }
    sort(b,b+cnt,cmp);
    ll ans=0;
    for(int i=0;i<cnt;i++){
        int fx=findfather(b[i].x);
        int fy=findfather(b[i].y);
        if(fx!=fy) {
            father[fx]=fy;
            ans+=b[i].val;
            if(b[i].x==0) dian.push_back(b[i].y);
            else if(b[i].y==0) dian.push_back(b[i].x);
            else lian.push_back(make_pair(b[i].x,b[i].y));
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",dian.size());
    for(int i=0;i<dian.size();i++){
        printf("%d ",dian[i]);
    }
    printf("\n");
     printf("%d\n",lian.size());
    for(int i=0;i<lian.size();i++){
        printf("%d %d\n",lian[i].first,lian[i].second);
    }
    //for(int )
    return 0;
}
