#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
//#define int long long

using namespace std;

const int N = (1e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);

char ans[111];
void solve(){
	int n;
	cin >> n;
	for(int i = 0;i < n; i++){
		ans[i] = '.';
	}
	int a, b, c;
	cin >> a >> b >> c;
	string s;
	cin >> s;
	int ans1 = 0;
	for(int i = 0;i < n; i++){
		if(s[i] == 'R' && b > 0){
			ans[i] = 'P';
			ans1++;
			b--;
		}
		if(s[i] == 'P' && c > 0){
			ans[i] = 'S';
			c--;
			ans1++;
		}
		if(s[i] == 'S' && a > 0){
			ans[i] = 'R';
			a--;
			ans1++;
		}
	}
	if(ans1 < (n + 1) / 2){
		cout << "NO\n";
	}
	else{
		for(int i = 0;i < n; i++){
			if(ans[i] == '.'){
				if(a > 0){
					ans[i] = 'R';
					a--;
				}
				else
				if(b > 0){
					ans[i] = 'P';
					b--;
				}
				else{
					ans[i] = 'S';
					c--;
				}
			}
		}
		cout << "YES\n";
		for(int i = 0;i < n; i++){
			cout << ans[i];
		}
		cout << endl;
	}
}
main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
