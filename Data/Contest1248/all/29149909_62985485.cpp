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
#define MAX 100005

void init(){
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	ll v1 = 0ll, v2 = 0ll;
	for(int i = 0; i<(n/2); i++){
		v1 += a[i];
	}
	for(int i = (n/2); i<n; i++){
		v2 += a[i];
	}
	ll ans = 1ll*v1*v1 + 1ll*v2*v2;
	cout << ans << endl;
	//fclose(stdout);
	return 0;
}