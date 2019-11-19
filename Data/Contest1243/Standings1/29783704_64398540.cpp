#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define fopen freopen("input.txt", "r", stdin)
#define pb push_back
#define prec(a) cout<<fixed;cout.precision(a);
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 9e18;
const int inf = 2e9;
template<class T>
void pr(T t) {cout << t << " ";}
template<class T, class ...Args>
void pr(T a, Args ...args) {cout << a << " ";pr(args...);}
template<class ...Args>
void prl(Args ...args) {pr(args...);cout << endl;}

int n, m, cnt;
set<int> remain,one[100010];
bool visit[100010];
vector<vector<int>> comp;
vector<int> tmp,newbie;
queue<int> q;
void bfs(int x){
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		remain.erase(x);
		visit[x]=true;
		tmp.pb(x);
		newbie.clear();
		for(auto i:remain){
			if(one[x].find(i)==one[x].end()){
				q.push(i);
				newbie.pb(i);
			}
		}
		for(auto i:newbie){
			remain.erase(i);
			visit[i]=true;
		}
	}
}
int main(){
	fastio;
	cin>>n>>m;
	for(int i=1;i<=n;i++) remain.insert(i);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		one[a].insert(b);
		one[b].insert(a);
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			tmp.clear();
			bfs(i);
			comp.pb(tmp);
		}
	}
	cout<<comp.size()-1;
}