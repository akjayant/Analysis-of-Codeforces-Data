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
	int t;
	cin >> t;
	for(int ii =0;ii < t;ii++) {
		int n;
		cin >> n;
		string s, t;
		cin >> s  >> t;
		int cnt =0;
		char aa ='9', bb ,c1,c2;
		vector < int > a1(30, 0);
		vector < int > a2(30, 0);
		for(int i =0;i < n;i++) {
			a1[fol(s[i])]++;
			a2[fol(t[i])]++;
			if(s[i] != t[i]){
				cnt++;
				if(aa == '9') {
					aa = s[i];
					c1 = t[i];
				} else {
					bb = s[i];
					c2 = t[i];
				}
			}
		}
		if(cnt == 2 ||cnt == 0) {
			if(cnt == 2) {
				if(aa == bb && c1 == c2) {
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
			} else {
				int gg =0;
				for(int i =0;i<30;i++){
					if(a1[i] > 0 && a2[i] > 0) {
						gg = 1;
						break;
					}
				}
				if(gg == 1) {
					cout<<"Yes\n";
				} else {
					cout<<"No\n";
				}
			}
		} else {
			cout << "No\n";
		}
	}
}