#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX1 = 1e5 + 7;

ll q, n, x, y, num[MAX1], mod = 1e9+7, p[26], flag;
string s, t;
vector <ll> ans;

int main(){
	fast_io;
    cin >> q;
    while (q--){
    	cin >> n >> s >> t;
    	fill(p, p+26, 0);
    	ans.clear();
    	for (int i = 0; i < n; ++i)	p[int(s[i])-97]++, p[int(t[i])-97]++;
    	flag = 0;
    	for (int i = 0; i < 26; ++i){
    		// cout << p[i] << sep;
    		if (p[i]%2 == 1)	flag = 1;
		}
		if (flag){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		for (int i = 0; i < n; ++i){
			if (s[i] == t[i])	continue;
			for (int j = i+1; j < n; ++j){
				if (s[i] == t[j]){
					ans.push_back(j), ans.push_back(j);
					ans.push_back(j), ans.push_back(i);
					swap(s[j], t[j]);
					swap(s[j], t[i]);
					// cout << 1 << i << endl;
					break;
				}
				if (s[j] == t[i]){
					ans.push_back(j), ans.push_back(j);
					ans.push_back(i), ans.push_back(j);
					swap(s[j], t[j]);
					swap(s[i], t[j]);
					// cout << 2 << i << endl;
					break;
				}
				if (s[i] == s[j]){
					ans.push_back(j), ans.push_back(i);
					swap(s[j], t[i]);
					// cout << 3 << i << endl;
					break;
				}
				if (t[i] == t[j]){
					ans.push_back(i), ans.push_back(j);
					swap(t[j], s[i]);
					// cout << 4 << i << endl;
					break;
				}
			}
			// cout << s << sep << t << endl;
		}
		cout << ans.size()/2 << endl;
		for (int i = 0; i < ans.size(); i += 2){
			cout << ans[i]+1 << sep << ans[i+1]+1 << endl;
		}
	}
    return 0;
}
/*                now or never                         */
