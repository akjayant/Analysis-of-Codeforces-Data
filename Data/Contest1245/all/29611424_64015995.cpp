#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> rt;
vector<int> sz;

int FIND(int n){
  if(n != rt[n]) rt[n] = FIND(rt[n]);
  return rt[n];
}
bool UNION(int n,int m){
  int rn = FIND(n),rm = FIND(m);
  if(rn == rm) return false;
  if(sz[rn] < sz[rm]){rt[rn] = rm; sz[rm] += sz[rn];}
  else{rt[rm] = rn; sz[rn] += sz[rm];}
  return true;
}

int main(){
  int N; cin >> N;
  for(int i = 0; i <= N; i++){rt.push_back(i); sz.push_back(1);}
  vector<ll> C(N,-1), K(N,-1);
  vector<ll> X(N,-1), Y(N,-1);
  for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  for(int i = 0; i < N; i++) cin >> C[i];
  for(int i = 0; i < N; i++) cin >> K[i];
  vector<pair<ll,pii> > edges;
  for(int i = 0; i < N; i++) edges.push_back({C[i],{0,i+1}});
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      edges.push_back({(K[i]+K[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j])),{i+1,j+1}});
    }
  }
  sort(edges.begin(),edges.end());
  vector<int> out1;
  vector<pii> out2;
  ll cost = 0;
  for(auto e : edges){
    if(UNION(e.second.first,e.second.second)){
      cost += e.first;
      if(e.second.first == 0) out1.push_back(e.second.second);
      else out2.push_back(e.second);
    }
  }
  cout << cost << "\n";
  cout << out1.size() << "\n";
  if(out1.size() > 0){
    cout << out1[0];
    for(int i = 1; i < out1.size(); i++) cout << " " << out1[i];
    cout << "\n";
  }
  cout << out2.size() << "\n";
  for(auto a : out2) cout << a.first << " " << a.second << "\n";
  return 0;
}
