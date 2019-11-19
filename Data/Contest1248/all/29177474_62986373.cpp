#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

#define rep(i,a) for (int i = 0; i < (a); ++i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	vll arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());

	ll lo = 0, hi = arr.size() - 1;
	bool hiSel = true;
	ll totH = 0;
	ll totW = 0;
	while (lo <= hi) {
		if (hiSel) {
			totW += arr[hi--];
			hiSel = false;
		}
		else {
			totH += arr[lo++];
			hiSel = true;
		}
	}
	ll sol = totH * totH + totW * totW;
	cout << sol;
	return 0;
}