#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int t, a, b, c;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int ans = 0;
		while(b >= 1 && c >= 2){
			b--, c -= 2;
			ans++;
		}
		while(a >= 1 && b >= 2){
			a--, b -= 2;
			ans++;
		}
		cout << 3 * ans << "\n";
	}

	return 0;
}
