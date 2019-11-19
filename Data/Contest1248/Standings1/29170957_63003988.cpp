#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans = -999999999999,ansx,ansy;
string str;
signed main() {
	cin >> n >> str;
	int a = 0,b = 0;
	for (size_t i = 0;i < str.size();i++) {
		if (str[i] == ')') a++;
		if (str[i] == '(') b++;
	}
	if (a ^ b) {
		printf("0\n1 1");
		return 0;
	}
	for (size_t i = 0;i < str.size();i++)
		for (size_t j = i+1;j < str.size();j++) {
			swap(str[i],str[j]);
			int cnt = 0,sum = 0,Min = 9999999;
			for (size_t k = 0;k < str.size();k++) {
				if (str[k] == ')') cnt--;
				if (str[k] == '(') cnt++;
				if (cnt < Min) {
					Min = cnt;
					sum = 1;
				} else if (cnt == Min) sum++;
			}
			if (sum > ans) {
				ans = sum;
				ansx = i;
				ansy = j;
			}
			swap(str[i],str[j]);
		}
	cout << ans << endl << ansx+1 << ' ' << ansy+1;
    return 0;
}