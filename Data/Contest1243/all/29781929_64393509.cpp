#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
 
set<int>adj[200001];
void solve(){
	int n,m;
	cin>>n>>m;
	set<int>s;
	rep(i,1,n+1)s.insert(i);
	vi ans;
	rep(i,1,m+1){
		int a,b;
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	while(!s.empty()){
		int i=*s.begin();
		queue<int>q;
		q.push(i);
		s.erase(i);
		int cnt=1;
		while(!q.empty()){
			auto cur=q.front();
			q.pop();
			vi toerase;
			toerase.reserve(sz(s));
			for(auto j:s){
				if(adj[cur].count(j))continue;
				q.push(j);
				toerase.emplace_back(j);
				cnt++;
			}
			for(auto j:toerase)s.erase(j);
		}
		ans.pb(cnt);
	}
	cout<<sz(ans) - 1 <<endl;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}