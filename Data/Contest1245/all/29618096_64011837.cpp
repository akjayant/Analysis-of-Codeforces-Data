#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
//typedef vector <vector <ll>> matrix;

const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(2e5 + 10);
const int MAX = 3e6 + 100;
const ll MAXE = (ll)(4e5 + 10);

typedef long double T;
typedef long double TT;
const ll INF = (ll)(1e9);
const TT EPS = (1e-8);


ll fib[MAXV];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);

	fib[0] = 1LL;
	fib[1] = 1LL;
	for(int i = 2;i < MAXV;i ++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	}

	string s;

	cin >> s;

	for(int i = 0;i < s.size();i ++){
		if(s[i] == 'w' || s[i] =='m'){
			cout << "0\n";
			return 0;
		}
	}

	ll cntn = 0, cntu = 0;

	ll ans = 1LL;

	if(s[0] == 'u')
		cntu ++;
	if(s[0] == 'n')
		cntn ++;

	s += '&';

	for(int i = 1;i < s.size();i ++){
		if(s[i] == 'n'){
			cntn ++;
		}
		else if(s[i - 1] == 'n'){
			ans = (ans * fib[cntn]) % MOD;
			cntn = 0;
		}

		if(s[i] == 'u'){
			cntu ++;
		}
		else if(s[i - 1] == 'u'){
			ans = (ans * fib[cntu]) % MOD;
			cntu = 0;
		}
	}

	cout << ans << "\n";

}
