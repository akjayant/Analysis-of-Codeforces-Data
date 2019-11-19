// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

bool othersort(const pi &a, const pi &b) {
	return a.second < b.second;
}

int main() {
	int n;
	int cur = 0;
	int mi = 1e9;
	int mict = 0;
	int a[300005];
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		char c;
		scanf("%c", &c);
		if (c == '(') a[i] = cur ++;
		if (c == ')') a[i] = cur --;
		mi = min(cur, mi);
	}
	if (cur != 0) {
		puts("0\n1 1");
		return 0;
	}
	vector<pi> A, B;
	for (int i=0; i<n; i++) {
		if (a[i] == mi) {
			mict ++;
			B.push_back({i, 0});
		}
		if (a[i] == mi+1) {
			B.push_back({i, 1});
			A.push_back({i, 0});
		}
		if (a[i] == mi+2) A.push_back({i, 1});
	}
	int i = -1;
	int l = 0;
	int ct = 0;
	int ma = 0;
	int ma_l = 0;
	int ma_r = 0;
	int oa = 0;
	int oa_l = 0;
	int oa_r = 0;
	for (auto e : A) {
		if (e.second == 0) {
			if (ma < ct) {
				ma = ct;
				ma_l = l;
				ma_r = e.first-1;
			}
			l = e.first;
			ct = 0;
		}
		else {
			ct ++;
		}
	}
	for (auto e : A) {
		if (e.second == 0) {
			if (ma < ct) {
				ma = ct;
				ma_l = l;
				ma_r = e.first-1;
			}
			ct = 0;
			break;
		}
		else {
			ct ++;
		}
	}
	for (auto e : B) {
		if (e.second == 0) {
			if (oa < ct) {
				oa = ct;
				oa_l = l;
				oa_r = e.first-1;
			}
			l = e.first;
			ct = 0;
		}
		else {
			ct ++;
		}
	}
	for (auto e : B) {
		if (e.second == 0) {
			if (oa < ct) {
				oa = ct;
				oa_l = l;
				oa_r = e.first-1;
			}
			ct = 0;
			break;
		}
		else {
			ct ++;
		}
	}
	if (mict + ma > oa) printf("%d\n%d %d\n", mict + ma, ((ma_l+n)%n)+1, ((ma_r+n)%n)+1);
	else printf("%d\n%d %d\n", oa, (oa_l+n)%n + 1, (oa_r+n)%n + 1);
	return 0;
}
