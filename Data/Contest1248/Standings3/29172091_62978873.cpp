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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;

	REP(t, T){
		ll N, M;
		cin >> N;
		ll parn = 0;
		ll iprn = 0;
		ll a;
		REP(i, N){
			cin >> a;
			if(a%2 == 0)
				parn++;
			else
				iprn++;
		}
		cin >> M;
		ll parm = 0;
		ll iprm = 0;
		ll b;
		REP(i, M){
			cin >> b;
			if(b%2 == 0)
				parm++;
			else
				iprm++;
		}

		cout << parm*parn + iprm*iprn << "\n";
	}

	
	return 0;
}