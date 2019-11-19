#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

string s;
int calc_beauty() {
	int min_occ = 0, mi = 1000, curr=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') curr++;
		else if (s[i] == ')') {
			curr--;
			if (curr == mi) min_occ++;
			else if (curr < mi) { min_occ = 1; mi = curr; }
		}
	}
	return min_occ;
}
int beauty(int i, int j) {
	swap(s[i], s[j]);
	int res = calc_beauty();
	swap(s[i], s[j]);
	return res;
}

int main() {
	int n; cin >> n >> s;
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') left++;
		else right++;
	}
	if (left != right) {
		cout << 0 << endl << "1 1" << endl;
		return 0;
	}
	int ma = beauty(0, 0); int besti = 0, bestj = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (s[i] == s[j]) continue;
			int be = beauty(i, j);
			if (be > ma) {
				besti = i;
				bestj = j;
				ma = be;
			}
		}
	}
	cout << ma << endl;
	cout << besti + 1 << " " << bestj + 1 << endl;

}