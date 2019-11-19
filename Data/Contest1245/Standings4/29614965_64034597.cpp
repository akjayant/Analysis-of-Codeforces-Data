#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct event {
  ll type,cost,a,b;

  event(ll t,ll c,ll aa,ll bb) {
    type = t;
    cost= c;
    a = aa;
    b = bb;
  }
};

vector<int> rnk,col,flag;

int find(int x) {
  if(x == col[x])
    return x;

  col[x] = find(col[x]);
  return col[x];
}

bool merge(int x,int y) {
  x = find(x);
  y = find(y);
  if(x == y || (flag[x] && flag[y]))
    return false;

  bool tmp = flag[x]|flag[y];
  flag[x] = flag[y] = tmp;

  if(rnk[x]>=rnk[y])
    col[y] = x;
  else
    col[x] = y;


  if(rnk[x] == rnk[y])
  rnk[x]++;  

  return true; 
}

int main() {

  int n;
  cin>>n;

  ll  x[n+1],y[n+1],i,j;

  for(i=1;i<=n;i++)
    cin>>x[i]>>y[i];

  ll c[n+1];
  col.push_back(0);
  for(i=1;i<=n;i++) {
    cin>>c[i];
    col.push_back(i);
  }

  ll k[n+1];
  for(i=1;i<=n;i++)
    cin>>k[i];

  vector<event> v;

  for(i=1;i<=n;i++) {
    for(j=i+1;j<=n;j++) {
      ll d = (k[i] + k[j])*(abs(x[i]-x[j]) + abs(y[i]-y[j]));
      event e(1,d,i,j);
      v.push_back(e);
    }
  }

  for(i=1;i<=n;i++) {
    event e(2,c[i],i,-1);
    v.push_back(e);
  }

  int len=v.size();

  sort(v.begin(),v.end(),
    [](event& w,event& y) {
      return w.cost < y.cost;
    });


  rnk.assign(n+1,0);
  flag.assign(n+1,0);

  ll ans = 0;

  vector<pair<int,int> > edges;
  vector<int> vert;

  for(i=0;i<len;i++) {
    ll type = v[i].type;
    ll cost = v[i].cost;
    ll a = v[i].a;
    ll b = v[i].b;

    //cout<<type<<": cost= "<<cost<<" "<<a<<" "<<b<<endl;

    if(type == 1) {
      if(merge(a,b)) {
        ans+=cost;
        edges.push_back(make_pair(a,b));
      }
    }

    else {
      ll x = find(a);
      if(flag[x]) {
        continue;
      }

      else {
        flag[x] = 1;
        ans+=cost;
        vert.push_back(a);
      }
    }
  }

  cout<<ans<<endl;
  cout<<vert.size()<<endl;

  for(auto it:vert)
    cout<<it<<" ";
  cout<<endl;

  cout<<edges.size()<<endl;

  for(auto it:edges) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  return 0;
}