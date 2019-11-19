#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int count_zeros(string const& s) {
	int mi = 0, result = 0;
	int cur = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			cur += 1;
		} else if (s[i] == ')') {
			cur -= 1;
			if (cur < mi) {
				mi = cur;
				result = 1;
			} else if (cur == mi) {
				result += 1;
			}
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) {
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	int result = count_zeros(s);
	int resulti = 1, resultj = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] != s[j]) {
				string t = s;
				swap(t[i], t[j]);
				int cnt = count_zeros(t);
				if (cnt > result) {
					result = cnt;
					resulti = i + 1;
					resultj = j + 1;
				}
			}
		}
	}
	cout << result << endl;
	cout << resulti << " " << resultj << endl;
}
