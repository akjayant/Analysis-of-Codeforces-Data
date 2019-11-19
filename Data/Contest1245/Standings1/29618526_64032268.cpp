#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

pll nx(pll A){
	if(A == pll(0, 0) || A == pll(-1, -1)) return pll(-1, -1);
	if(A.S == 0 && A.F % 2 == 0) return {A.F - 1, A.S};
	if(A.S == 9 && A.F % 2 == 1) return {A.F - 1, A.S};
	if(A.F%2 == 1) return {A.F, A.S + 1};
	if(A.F%2 == 0) return {A.F, A.S - 1};
	return {-1, -1};
}
pll get(pll A, ll x){
	for(int i = 0; i< x; i++) A = nx(A);
}
ll v[12][12];
ld dp[12][12];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> v[i][j];
	
	dp[0][0] = 0;
	for(int i = 0; i < 10; i++){
		for(int jj = 0; jj < 10; jj++){
			ll j = (i % 2 ? 9 - jj : jj);
			if(i == 0 && j == 0) continue;
			pll B = {i, j};
			ll cnt = 0;
			ld sm = 0;
			for(int k = 1; k <= 6; k++){
				B = nx(B);
				if(B == pll(-1, -1)) continue;
				sm += min(dp[B.F][B.S], dp[B.F - v[B.F][B.S]][B.S]);
				cnt ++;
			}
			//cerr << cnt << '\n';
			dp[i][j] = (sm + 6.0) / cnt;
		}
	}
	
	
	cout << fixed << setprecision(16) << dp[9][0];
	
	return 0;
}
