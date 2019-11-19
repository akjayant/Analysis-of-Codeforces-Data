#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define INF 1000000000ll
#define MAX 1000005

void init(){
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	ll n;
	cin >> n;
	ll g = n;
	for(ll i = 2; i*i<=n; i++){
		if(n%i == 0){
			g = __gcd(g, n/i);
			g = __gcd(g, i);
		}
	}
	cout << g << endl;
	//fclose(stdout);
	return 0;
}