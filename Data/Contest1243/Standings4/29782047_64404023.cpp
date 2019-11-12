#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <set>
#include <fstream>
typedef long long ll;

using namespace std;




ll MOD = 1e9 + 7;

vector<ll> divisors;

void f(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if(i!=n/i)
			divisors.push_back(n/i);
		}
	}
	
}

int fnd(string s, int st, char c) {
	for (int i = st; i < s.length(); i++) {
		if (s[i] == c) return i;
	}
	return -1;
}

int main()
{
	
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<pair<int, int>> ans;

		bool ch = false;


		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				int pos = fnd(s1, i + 1, s1[i]);
				if (pos != -1) {
					ans.push_back(make_pair(pos + 1, i + 1));
					swap(s1[pos], s2[i]);
				}
				else {
					pos = fnd(s2, i + 1, s1[i]);
					if (pos != -1) {
						ans.push_back(make_pair(i+2, pos+1));
						swap(s1[i + 1], s2[pos]);
						ans.push_back(make_pair(i + 2, i+1));
						swap(s1[i + 1], s2[i]);
					}
					else {
						ch = true;
						break;
					}
				}
			}
		}
		
		if (ch) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}
		
		
	}
	
	

}


