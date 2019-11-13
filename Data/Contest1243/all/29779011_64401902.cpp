#include <bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2")
#define int long long
int  md = 1e9 + 7;
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
int fol( char a) {
	int x = a -'a';
	return x;
}
main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	for(int ii =0; ii < q; ii++) {
		int n;
		cin >> n;
		int kos = n;
		string ss, tt, s = "", t = "";
		cin >> ss >> tt;
		vector < int > a1;
		for(int i =0; i < n; i++) {
			if(ss[i] != tt[i]) {
				s += ss[i];
				t += tt[i];
				a1.push_back(i + 1);
			}
		}
		n = s.size();
		vector < pair < int , int > > ans;
		for(int i =0; i < n; i++) {
			int flag = 0;
			for(int j = i + 1; j < n; j++) {
				if(t[i] == t[j]) {
					ans.push_back({a1[i], a1[j]});
					swap(s[i], t[j]);
					flag = 1;
					break;	
				}
			}
			if(flag == 0) {
				for(int j = i + 1; j < n; j++) {
					if(s[j] == t[i]) {
						ans.push_back({a1[j], a1[j]});
						swap(s[j], t[j]);
						ans.push_back({a1[i], a1[j]});
						swap(t[j], s[i]);
						break;	
					} 
				}
			}
		}
		if(s == t) {
			if(ans.size() > kos * 2) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
				cout << ans.size()<<"\n";
				for(int i =0;i<ans.size();i++) {
					cout << ans[i].first << " " << ans[i].second << "\n";
				}
			}
		} else {
			cout << "No\n";
		}
	}
}