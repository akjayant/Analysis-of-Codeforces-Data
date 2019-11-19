#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;

int n;
string s;

int getBeauty() {
	int res = 0;
        int val = 0;
	int mn = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		val += ((s[i] == '(')?1: -1);
		if (val < mn) {
			mn = val;
			res = 0;
		}
		if (mn == val)
			res++;
	}
	return (val == 0)?res: 0;
}

int main() {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#else
//	freopen("input.txt","r",stdin);
//	freopen("output.txt", "w",stdout);
#endif
	cin >> n;
	cin >> s;	
	int bt = getBeauty();
	if (bt == 0) {
		cout << 0 << endl;
		cout << "1 1" << endl;
		return 0;
	}
	int best = bt;
	int a = 0;
	int b = 0;	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(s[i], s[j]);
			int nb = getBeauty();
			swap(s[i], s[j]);
			if (nb > best) {
				best = nb;
				a = i;
				b = j;
			}
		}
	}
	cout << best << endl;
	cout << a + 1 << " " << b + 1 << endl;
	return 0;
}