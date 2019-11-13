#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef pair <int, pii> piii;
#define fr first
#define sc second
#define pb push_back
#define ppb pop_back()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define mpr make_pair
vector <int> g[301];
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int n2 = n * n;
	for(int i = 1;i <= n; ++ i){
		if(i & 1){
			for(int j = 1;j <= n; ++ j){
				g[j].pb(n2);
				--n2;
			}
		}
		else{
			for(int j = n;j >= 1; -- j){
				g[j].pb(n2);
				--n2;
			}
		}
	}
	for(int i = 1;i <= n; ++ i){
		for(auto to : g[i])
			cout << to << " ";
		cout << endl;
	}
	return 0;
}