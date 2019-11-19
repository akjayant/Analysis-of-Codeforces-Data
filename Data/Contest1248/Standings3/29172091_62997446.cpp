#include <bits/stdc++.h>

	using namespace std;

#define ll long long
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n; i>=0; i--)
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define st first
#define nd second
#define vi vector<int>
#define vii vector< vi >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define endl "\n"


ll N, M;
ll mod = 1000000007;
ll MEMO[100200];

ll Fibo(ll k){
	if(k == 0)
		return 1;
	if(k == 1)
		return 2;
	if(MEMO[k] != 0)
		return MEMO[k];
	return MEMO[k] = (Fibo(k-1) + Fibo(k-2))%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	ll ans = Fibo(N-1) + Fibo(M-1) - 1;
	ans *= 2;
	ans %= mod; 

	cout << ans << "\n";
	return 0;
}