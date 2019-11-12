#include<bits/stdC++.H>
using namespace std;
int n, k, a[200000];
#define pb push_back
int main(){
	cin >> k;
	string s, t;
	vector <int>vec;
	for (int it = 1; it <= k; it++) {
		cin >> n;
		cin >> s >> t;
		vec.clear();

		for (int i = 0; i < s.size(); i++) {
		 	if (s[i] != t[i]) vec.pb(i);
		}
		if (vec.size() == 1 or vec.size() > 2) {
		 	cout << "No" << endl;
		 	continue;
		}

		if (vec.size() == 0 or (s[vec[0]] == s[vec[1]] and t[vec[0]] == t[vec[1]]))
		cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

}
