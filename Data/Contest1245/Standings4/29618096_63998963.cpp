#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
//typedef vector <vector <ll>> matrix;

const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(6e3 + 10);
const int MAX = 3e6 + 100;
const ll MAXE = (ll)(4e5 + 10);

typedef long double T;
typedef long double TT;
const ll INF = (ll)(1e9);
const TT EPS = (1e-8);




int main(){
	cin.sync_with_stdio(0);cin.tie(0);

	int cases;

	cin >> cases;

	while(cases --){
		ll a , b;

		cin >> a >> b;

		if(__gcd(a, b) == 1LL){
			cout << "Finite\n";
		}
		else
			cout << "Infinite\n";
	}
}
