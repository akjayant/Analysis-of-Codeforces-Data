/**
 *    created by : PawPaw       
**/

#include<bits/stdc++.h>
using namespace std;

#define N 2123

int par[N], sz[N], source[N];
long long c[N];
bool isStation[N];

void pre(){
  iota(par, par+N, 0);
  fill(sz, sz+N, 1);
  fill(isStation, isStation+N, true);
  iota(source, source+N, 0);
}

int find(int n){
    while(n != par[n]) n = par[n];
    return n;
}

void merge(int a, int b, int minPower, int sourceMin){
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    c[a] = minPower;
    source[a] = sourceMin;
}

int solve(){
  int n;
  long long x[N], y[N], k[N], totalCost = 0, cost, currMin, currMax, srcMin, srcMax;
  vector<pair<long long, pair<int, int>>> adj;
  vector<pair<int, int>> ansAdj;
  vector<int> station;
  pre();
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> x[i] >> y[i];
  }
  for(int i = 0 ; i < n ; i++){
    cin >> c[i];
    totalCost += c[i];
  }
  for(int i = 0 ; i < n ; i++){
    cin >> k[i];
  }

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(i != j){
        cost = (abs(x[i]-x[j]) + abs(y[i]-y[j])) * (k[i]+k[j]);
        adj.push_back(make_pair(cost, make_pair(i, j)));
      }
    }
  }
  sort(adj.begin(), adj.end());
  for(int i = 0 ; i < (int)adj.size() ; i++){
    int a = find(adj[i].second.first);
    int b = find(adj[i].second.second);
    if(a != b){
      if(c[a] > c[b]){
        currMax = c[a];
        srcMax = source[a];
      } else {
        currMax = c[b];
        srcMax = source[b];
      }
      if(adj[i].first <= currMax){
        isStation[srcMax] = false;
        if(c[a] < c[b]){
          currMin = c[a];
          srcMin = source[a];
        } else {
          currMin = c[b];
          srcMin = source[b];
        }
        ansAdj.push_back(make_pair(adj[i].second.first, adj[i].second.second));
        totalCost -= currMax;
        totalCost += adj[i].first;
        merge(a, b, currMin, srcMin);
      }
    }
  }
  for(int i = 0 ; i < n ; i++){
    if(isStation[i]) station.push_back(i+1); 
  }
  cout << totalCost << endl;
  cout << (int)station.size() << endl;
  for(int i = 0 ; i < (int)station.size() ; i++){
    if(i) cout << " ";
    cout << station[i];
  }
  cout << endl;
  cout << ansAdj.size() << endl;
  for(int i = 0 ; i < (int)ansAdj.size() ; i++) cout << ansAdj[i].first+1 << " " << ansAdj[i].second+1 << endl;
  return 0;
}

void fun(){
  int t = 1;
  // cin >> t;
  while(t--) solve();
} 

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("fi", "r", stdin);
    freopen("fo", "w", stdout);
    clock_t startClock, endClock;
    startClock = clock();
  #endif

  fun();

  #ifndef ONLINE_JUDGE
    endClock = clock(); 
    cout << "Time taken by program is : " << fixed <<  double(endClock - startClock) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec " << endl; 
  #endif
  
  return 0;
}