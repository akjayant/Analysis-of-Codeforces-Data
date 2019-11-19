#include <bits/stdc++.h>
 
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("anime.in", "r", stdin); freopen("anime.out", "w", stdout);

typedef long long ll;
typedef long double ld;
 
using namespace std;

signed main(){
	ios;
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		string s;
		cin >> s;
		int l = -1;
		for (int i = 0; i < n; i++){
			if (s[i] == '1'){
				l = i;
				break;
			}
		}
		int r = -1;
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == '1'){
				r = i;
				break;
			}
		}
		if (l == -1 || r == -1){
			cout << n << endl;
		}else{
			cout << max((n - l) * 2, (r + 1) * 2) << endl;
		}
	}
}