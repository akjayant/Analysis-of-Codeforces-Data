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
		cin >> n;
		string s;
		cin >> s;
		int a = -1, b = -1;
		for (int i = 0; i < n; i ++){
			if (s[i] == '1')
				a = i;
		}
		for (int j = n - 1; j >= 0; j --){
			if (s[j] == '1')
				b = j;
		}
		if (a == -1){
			cout << n << '\n';
			continue;
		}
		cout << max((a + 1) * 2, (n - b) * 2) << '\n';
	}
}
