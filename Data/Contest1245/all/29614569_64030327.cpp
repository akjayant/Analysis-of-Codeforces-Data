#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
  cin >> n;
  
  vector<ll> x(n+1),y(n+1);
  for(int i = 1;i < n+1;i++){
    cin >> x[i] >> y[i];
  }
  
  vector<ll> c(n+1);
  for(int i = 1; i < n+1; i++){
    cin >> c[i];
    
  }
  
  vector<ll> k(n+1);
  for(int i = 1; i < n+1; i++){
    cin >>k[i];
  }
  
  
  vector<int> e(n+1,0);//0 self !0 (c[i]=x[i]-x[e[i]]+y[i]-y[e[i]]*k[i] +k[e[i]])
  
  vector<int> ansStations;
  vector<pair<int,int>> ansConns;
  ll cost = 0;
  
  vector<bool> used(n+1,false);
  int usednum = 0;
  
  while(usednum<n){
    
    
    int mn=-1;
    for(int i = 1; i < n+1; i++){
      if(!used[i] && mn==-1)mn=i;
      if(!used[i] && c[i] < c[mn])mn = i;
    }
    
    if(e[mn]==0){
      ansStations.push_back(mn);
    }else{
      ansConns.push_back({e[mn],mn});
    }
    
    used[mn]=true;
    cost+=c[mn];
    usednum++;
    
    for(int i = 1; i < n+1; i++){
      if(!used[i]){
        ll dist = abs(x[i]-x[mn])+abs(y[i]-y[mn]);
        ll new_cost = dist*(k[i]+k[mn]);
        if(new_cost<c[i]){
          c[i]=new_cost;
          e[i]=mn;
        }
      }
    }
    
    
  }
  
  cout <<cost <<endl;
  cout << ansStations.size() <<endl;
  for(int i = 0; i < ansStations.size(); i++){
    cout << ansStations[i] << " " ;
  }cout <<endl;
  cout << ansConns.size()<<endl;
  for(int i = 0; i < ansConns.size(); i++){
    cout << ansConns[i].first << " " << ansConns[i].second <<endl;
  }
  
  
  
}
