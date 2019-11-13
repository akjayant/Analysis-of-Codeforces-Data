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
	int k;
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i<n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int ans = 1;
		int h = a[n-1], w = 1;
		for(int i = n-2; i>=0; i--){
			w++;
			h = a[i];
			ans = max(ans, min(h, w));
		}
		cout << ans << endl;
	}
	//fclose(stdout);
	return 0;
}