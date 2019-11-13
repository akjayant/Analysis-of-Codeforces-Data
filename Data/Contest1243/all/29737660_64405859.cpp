#include<bits/stdc++.h>
 
/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace std;
 
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
const LL MOD = 1000000000 + 7;
const LD EPS = 0.0000001 ;
#define MPP(a, b, c) MP(MP(a, b), c)
#define PII pair<pair<LL,LL>, LL>
 
LL pows(LL a, LL b)
{
	if (b == 0) return 1LL;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2) temp = (temp * a) % MOD;
	return temp;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	int tc; cin >> tc;

 	while (tc--){
 		int n; cin >> n;
 		string s; cin >> s;
 		string t; cin >> t;
 		vector<pair<char,int> > as, at;
 		int arr[26];
 		memset(arr, 0, sizeof(arr));
 		for (int i = 1; i <= n; i++){
 			if (s[i - 1] == t[i - 1]) continue;
 			as.PB(MP(s[i - 1], i));
 			at.PB(MP(t[i - 1], i));
 			arr[s[i - 1] - 'a']++;
 			arr[t[i - 1] - 'a']++;
 		}
 		bool flag = true;
 		for (int i = 0; i < 26; i++){
 			if (arr[i] % 2) flag = false;
 		}

 		if (flag == false){
 			cout << "No\n";
 			continue;
 		}
 		vector<pair<int,int> > ans;
 		cout << "YES\n";
 		for (int i = 0; i < as.size(); i++){
 			bool found = false;
 			if (as[i].fi == at[i].fi) continue;
 			for (int j = i + 1; j < as.size(); j++){
 				if (as[i].fi == as[j].fi){
 					found = true;
 					ans.PB(MP(as[j].se, as[i].se));
 					char temp = at[i].fi;
 					at[i].fi = as[j].fi;
 					as[j].fi = temp;
 					break;
 				}
 			}
 			if (found) continue;
 			for (int j = i + 1; j < at.size(); j++){
 				if (as[i].fi == at[j].fi){
 					ans.PB(MP(as.back().se, at[j].se));
 					char temp = as.back().fi;
 					as.back().fi = at[j].fi;
 					at[j].fi = temp;
 					ans.PB(MP(as.back().se, at[i].se));
 					temp = as.back().fi;
 					as.back().fi = at[i].fi;
 					at[i].fi = temp;
 					break;
 				}
 			}
 		}
 		cout << ans.size() << endl;
 		for (auto it : ans) cout << it.first << " " << it.second << endl;
 	}

	return 0;
}