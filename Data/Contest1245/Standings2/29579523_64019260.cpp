#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
const double pi = acos(-1.0);

// 1->n
//
// (x,y)


// c(i) power
// i<-> k[i]+k[j] * (|xi-xj|+|yi-yj|)

// 最小生成树?
// root -> p = c[p]
// p[i] <-> pj  =


vector<tuple<ll,int,int>> edge;

int fa[2010];
int n;

int getfa(int i){
  return fa[i] == i ? i : (fa[i] = getfa(fa[i]));
}
void linknode(int v1,int v2){
  fa[getfa(v1)] = getfa(v2);
}

int x[2010];
int y[2010];
ll k[2010];

vector<pair<int,int> > link;

int main(){
  cin>>n;
  rep(i,0,n+1){
    fa[i]=i;
  }
  rep(i,1,n+1){
    scanf("%d %d",x+i,y+i);
  }
  rep(i,1,n+1){
    int c;
    scanf("%d",&c);
    edge.pb({c,0,i});
  }
  rep(i,1,n+1){
    scanf("%d",k+i);
  }
  rep(i,1,n+1){
    rep(j,i+1,n+1){
      ll cost = (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
      edge.pb({cost,i,j});
    }
  }
  sort(edge.begin(),edge.end());
  ll anscost = 0;
  for(auto item :edge){
    auto [cost,pi,pj] = item;
    if(getfa(pi) == getfa(pj))continue;
    anscost+=cost;
    link.pb({pi,pj});
    linknode(pi,pj);
  }
  vector<int>lighten ;
  for(auto item:link){
    if(item.first == 0){
      lighten.pb(item.second);
    }
  }
  printf("%lld\n",anscost);
  printf("%d\n",lighten.size());
  for(auto item:lighten){
    printf("%d ",item);
  }
  printf("\n");
  printf("%d\n",n-lighten.size());
  for(auto item:link){
    if(item.first != 0){
      printf("%d %d\n",item.first,item.second);
    }
  }


  return 0;
}
