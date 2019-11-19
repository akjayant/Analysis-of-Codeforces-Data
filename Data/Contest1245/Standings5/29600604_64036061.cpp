// g++ -std=c++14
#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
#define int ll

vector<int>nodes;
vector<int>wt;
int ans = 0;
void initialize(int n, vector<int>& well){
	nodes.resize(n);
	wt.resize(n);
	for(int i = 0; i < n; i++){
		nodes[i] = i;
		wt[i] = well[i];
	}
}
int findRoot(int ind){
	if(nodes[ind] == ind){
		return ind;
	}
	return nodes[ind] = findRoot(nodes[ind]);
}

void unionn(int ind1, int ind2){
	int root1 = findRoot(ind1);
	int root2 = findRoot(ind2);
	if(root1 == root2){
		return;
	}
	if(wt[root1] < wt[root2]){
		nodes[root2] = root1;
		ans -= wt[root2];
	}
	else{
		nodes[root1] = root2;
		ans -= wt[root1];
	}
}

vector<pair<int, int> >ed;

int MinConnectingCost(vector<int>& well, vector<vector<int> >& pipe){
	int n = well.size();
	if (n == 0) {
		return ans;
}
	initialize(n, well);
	for(int i = 0; i < n; i++){
		ans += well[i];
	}
	vector<vector<int> >sortedPipes;
	// set<vector<int> >sortedPipes;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			sortedPipes.push_back({pipe[i][j], i, j});
			// sortedPipes.insert({pipe[i][j], i, j});
		}
	}
	sort(all(sortedPipes));
	for (auto edge: sortedPipes) {
		int weight = edge[0];
		int house1 = edge[1];
		int house2 = edge[2];
		int root1 = findRoot(house1);
		int root2 = findRoot(house2);
		if (root1 != root2) {
			int maxx = max(well[root1], well[root2]);
			if (maxx > weight) {
				ans += weight;
				unionn(house1, house2);
				ed.pb(mp(house1, house2));
			}
		}
	}
	return ans;
}

int getDist(pair<int, int>& p1, pair<int, int>& p2){
	return abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
}

int32_t main(){
  _
  int n;
  cin >> n;
  vector<pair<int, int> >points(n);
  for(int i = 0; i < n; i++){
  	cin >> points[i].fi >> points[i].se;
  }
  vector<int>cost(n);
  for(int i = 0; i < n; i++){
  	cin >> cost[i];
  }
  vector<int>perk(n);
  for(int i = 0; i < n; i++){
  	cin >> perk[i];
  }
  vector<vector<int> >mat(n, vector<int>(n));
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < n; j++){
  		mat[i][j] = getDist(points[i], points[j]) * (perk[i] + perk[j]);
  	}
  }
  cout << MinConnectingCost(cost, mat) << "\n";
  vector<int>arr;
  for(int i = 0; i < n; i++){
  	if(nodes[i] == i){
  		arr.pb(i);
  	}
  }
  cout << arr.size() << "\n";
  for(int i = 0; i < arr.size(); i++){
  	cout << arr[i] + 1 << " ";
  }
  cout << "\n";
  cout << ed.size() << "\n";
  for(int i = 0; i < ed.size(); i++){
  	cout << ed[i].fi + 1 << " " << ed[i].se + 1 << "\n";
  }
  return 0;
}
