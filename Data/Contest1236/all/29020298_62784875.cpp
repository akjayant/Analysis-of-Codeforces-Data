//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;

void Main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	int ans = 0;
	cin >> a >> b >> c;
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			int Nb = b - 2 * i - j;
			int Na = a - i;
			int Nc = c - 2 * j;
			if (Nb >= 0 && Na >= 0 && Nc >= 0) ans = max(ans, 3 * i + 3 * j); 
		}
	}	
	cout << ans << '\n';









	return ;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		Main();
	}
}




