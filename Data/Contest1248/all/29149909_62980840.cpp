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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int p[n];
		int pe = 0, po = 0;
		for(int i = 0; i<n; i++){
			cin >> p[i];
			if(p[i]%2 == 0)pe++;
			else po++;
		}
		int m;
		cin >> m;
		int q[m];
		int qe = 0, qo = 0;
		for(int i = 0; i<m; i++){
			cin >> q[i];
			if(q[i]%2 == 0)qe++;
			else qo++;
		}
		ll ans = 1ll*pe*qe + 1ll*po*qo;
		cout << ans << "\n"; 
	}
	//fclose(stdout);
	return 0;
}