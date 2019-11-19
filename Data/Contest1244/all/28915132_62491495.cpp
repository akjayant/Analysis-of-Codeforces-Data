#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
#define N 100010
using namespace std;
ll A[N][3], dp[N][4][4],  ans[N];
pair<ll, pair<ll, ll> > maxi[N];
pair<ll, ll> bk[N][4][4];
vector<int> graph[N];
pair<int, int> getinv(int a){
	if(a == 0){
		return mp(1, 2);
	}
	else if(a == 1){
		return mp(0, 2);
	}
	else return mp(0, 1);
}
ll getmin(int s, int d, int r, int p){
	//cerr << s << " " << d << " " << r << '\n';
	if(dp[s][d][r] != -1)
		return dp[s][d][r];
	maxi[s] = mp(1e18, mp(1e18, 1e18));
	vector<int> df;
	for(int i = 0; i < graph[s].size(); i++){
		if(graph[s][i] != p){
			df.pb(graph[s][i]);
		}
	}
	pair<int, int> inv = getinv(d);
	if(df.size() == 1){
		if(r == 3){
			maxi[s] = min(mp(A[s][d] + getmin(df[0],inv.first, d, s), mp(inv.first, 1e18)), mp(A[s][d] + getmin(df[0],inv.second, d, s), mp(inv.second, 1e18)));	
		}
		else if(inv.first == r){
			maxi[s] = mp(A[s][d] + getmin(df[0], inv.second, d, s), mp(inv.second, 1e18));
		}
		else{
			maxi[s] = mp(A[s][d] + getmin(df[0], inv.first, d, s), mp(inv.first, 1e18));
		}
	}
	else if(df.size() == 2){
		if(r != 3){
			maxi[s] = mp(1e18, mp(1e18, 1e18));
		}
		else
		maxi[s] = min(mp(A[s][d] + getmin(df[0], inv.first, d, s) + getmin(df[1], inv.second, d, s), mp(inv.first, inv.second)), mp(A[s][d] + getmin(df[1], inv.first, d, s) + getmin(df[0], inv.second, d, s), mp(inv.second, inv.first)));
	}
	else{
		maxi[s] = mp(A[s][d], mp(1e18, 1e18));
	}
	bk[s][d][r] = maxi[s].second;
	return dp[s][d][r] = maxi[s].first;
}
void dfs(int s, int d, int r, int p){
	vector<int> df;
	for(int i = 0; i < graph[s].size(); i++){
		if(graph[s][i] != p){
			df.pb(graph[s][i]);
		}
	}
	if(df.size() == 1){
		ans[df[0]] = bk[s][d][r].first;
		dfs(df[0], bk[s][d][r].first, d, s);
	}
	else if(df.size() == 2){
		ans[df[0]] = bk[s][d][r].first;
		ans[df[1]] = bk[s][d][r].second;
		dfs(df[0], bk[s][d][r].first, d, s);
		dfs(df[1], bk[s][d][r].second, d, s);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)cin >> A[i][0];
	for(int i = 0; i < n; i++)cin >> A[i][1];
	for(int i = 0; i < n; i++)cin >> A[i][2];
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		graph[a - 1].pb(b - 1);
		graph[b - 1].pb(a - 1);
	}
	for(int i = 0; i < n; i++){
		if(graph[i].size() > 2){
			cout << -1 << '\n';
			return 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	pair<ll, ll> mini = mp(1e18, 1e18);
	for(int i = 0; i < 3; i++){
		mini = min(mini, mp(getmin(0, i, 3, -1), 1LL * i));
	}
	if(mini.first > 1e15){
		cout << -1 << '\n';
		return 0;
	}
	cout << mini.first << '\n';
	ans[0] = mini.second ;
	dfs(0, mini.second, 3, -1);
	for(int i = 0; i < n; i++)
		cout << ans[i]  + 1<< " ";
	cout << '\n';


}