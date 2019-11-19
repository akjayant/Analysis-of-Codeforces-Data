#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int brackets_min = 1;
	vi brackets(N);
	if (S[0] == '(')
		brackets[0] = 1;
	else
		brackets[0] = -1;
	rep(i, N - 1) {
		brackets[i + 1] = brackets[i];
		if (S[i + 1] == '(')
			brackets[i + 1]++;
		else
			brackets[i + 1]--;
		brackets_min = min(brackets_min, brackets[i + 1]);
	}
	vector<vi> min_num(N);
	vi min_num_tmp(3, 0);
	min_num.push_back(min_num_tmp);
	rep(i, N - 1) {
		min_num_tmp = min_num[i];
		if (brackets[i] == brackets_min)
			min_num_tmp[0]++;
		else if (brackets[i] == brackets_min + 1)
			min_num_tmp[1]++;
		else if (brackets[i] == brackets_min + 2)
			min_num_tmp[2]++;
		min_num.push_back(min_num_tmp);
	}
	int l = 0, r = 0;
	int ans = 0;
	int bmin = 10;
	if (brackets[N - 1] == 0) {
		rep(i, N) {
			rep(j, N) {
				if (i >= j)
					continue;
				if (S[i] == S[j])
					continue;
				if (S[i] == '(') {
					int bmin = 10;
					rep(k, N) {
						int btmp = brackets[k];
						if (i <= k && k < j)
							btmp -= 2;
						bmin = min(bmin, btmp);
					}
					int anstmp = 0;
					rep(k, N) {
						int btmp = brackets[k];
						if (i <= k && k < j)
							btmp -= 2;
						if (bmin == btmp)
							anstmp++;
					}
					if (ans < anstmp) {
						ans = anstmp;
						l = i;
						r = j;
					}
				}
				else {
					int bmin = 10;
					rep(k, N) {
						int btmp = brackets[k];
						if (i <= k && k < j)
							btmp += 2;
						bmin = min(bmin, btmp);
					}
					int anstmp = 0;
					rep(k, N) {
						int btmp = brackets[k];
						if (i <= k && k < j)
							btmp += 2;
						if (bmin == btmp)
							anstmp++;
					}
					if (ans < anstmp) {
						ans = anstmp;
						l = i;
						r = j;
					}
				}
			}
		}

		rep(k, N) {
			int btmp = brackets[k];
			bmin = min(bmin, btmp);
		}
		int anstmp = 0;
		rep(k, N) {
			int btmp = brackets[k];
			if (bmin == btmp)
				anstmp++;
		}
		if (ans < anstmp) {
			ans = anstmp;
			l = 0;
			r = 0;
		}
	}
	l++;
	r++;
	cout << ans << endl;
	cout << l << " " << r << endl;
	return 0;
}