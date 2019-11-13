//besmellah
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t --){
		int n;
		int a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		int x = 0, y = 0, z = 0;
		cin >> s;
		for (auto c: s){
			if (c == 'R')
				x ++;
			if (c == 'P')
				y ++;
			if (c == 'S')
				z ++;
		}
		if (min(b, x) + min(c, y) + min(a, z) >= (n + 1) / 2){
			cout << "YES\n";
			string t = s;
			vector <int> vec;
			for (int i = 0; i < n; i ++){
				if (s[i] == 'R' && b){
					t[i] = 'P';
					b --;
				}
				else if (s[i] == 'P' && c){
					t[i] = 'S';
					c --;
				}
				else if (s[i] == 'S' && a){
					t[i] = 'R';
					a --;
				}
				else{
					vec.push_back(i);
				}
			}
			for (auto i: vec){
				if (a){
					t[i] = 'R';
					a --;
				}
				else if (b){
					t[i] = 'P';
					b --;
				}
				else{
					t[i] = 'S';
					c --;
				}
			}
			cout << t << '\n';
		}
		else
			cout << "NO\n";
	}
}
