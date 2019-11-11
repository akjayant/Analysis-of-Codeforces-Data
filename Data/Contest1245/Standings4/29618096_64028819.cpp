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
const int MAX = 3e2 + 100;
const ll MAXE = (ll)(4e5 + 10);

typedef long double T;
typedef long double TT;
const ll INF = (ll)(1e9);
const TT EPS = (1e-8);

char ans[MAXV];


int main(){
	cin.sync_with_stdio(0);cin.tie(0);

	int cases;

	cin >> cases;

	while(cases --){

		ll n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;

		ll cnt = 0;
		for(int i = 0;i < n;i ++)
			ans[i] = '#';

		for(int i = 0;i < n;i ++){
			if(s[i] == 'P'){
				if(c > 0){
					c --;
					cnt ++;
					ans[i] = 'S';
				}
			}
		}

		for(int i = 0;i < n;i ++){
			if(s[i] == 'R'){
				if(b > 0){
					b --;
					cnt ++;
					ans[i] = 'P';
				}
			}
		}

		for(int i = 0;i < n;i ++){
			if(s[i] == 'S'){
				if(a > 0){
					a --;
					cnt ++;
					ans[i] = 'R';
				}
			}
		}

		for(int i = 0;i < n;i ++){
			if(ans[i] == '#'){
				if(a > 0){
					ans[i] = 'R';
					a --;
				}
				else if(b > 0){
					ans[i] = 'P';
					b --;
				}
				else if(c > 0){
					ans[i] = 'S';
					c --;
				}
			}
		}

		//cout << cnt << "\n";

		if(cnt >= (n + 1) / 2){
			cout << "YES\n";
			for(int i = 0;i < n;i ++)
				cout << ans[i];
			cout << '\n';
		}
		else{
			cout << "NO\n";
		}
	}
}
