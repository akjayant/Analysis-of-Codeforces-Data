#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ll> point;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;


		map<char, int> mp;
		cin >> mp['R'];
		cin >> mp['P'];
		cin >> mp['S'];

		string s;
		cin >> s;

		int win = 0;
		vector<char> ans(n, '?');

		for(int i = 0; i < n; i++){
			if(s[i] == 'R'){
				if(mp['P'] > 0){
					win++;
					mp['P']--;
					ans[i] = 'P';
				}
			}

			if(s[i] == 'P'){
				if(mp['S'] > 0){
					win++;
					mp['S']--;
					ans[i] = 'S';
				}
			}

			if(s[i] == 'S'){
				if(mp['R'] > 0){
					win++;
					mp['R']--;
					ans[i] = 'R';
				}

			}
		}

		if(win >= (n + 1) / 2){
			cout << "YES" << endl;

			for(int i = 0; i < n; i++){
				if(ans[i] == '?'){
					if(mp['R'] > 0)
					{
						ans[i] = 'R';
						mp['R']--;
					}
					else if(mp['S'] > 0){
						ans[i] = 'S';
						mp['S']--;
					}
					else if(mp['P'] > 0){
						ans[i] = 'P';
						mp['P']--;
					}

				}
			}

			for(int i = 0; i < n; i++)
				cout << ans[i];
			cout << endl;
		}
		else
			cout << "NO" << endl;

	}

	return 0;
}