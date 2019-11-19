//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e5 + 10;
map <int, int> cnt;
set <pair <int, int>> M;
int a[maxn];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (auto c: cnt){
		M.insert(c);
	}
	while (k > 0){
		if (M.size() == 1){
			break;
		}
		int x = (*M.begin()).second, y = (*M.rbegin()).second;
		if (x <= y){
			auto q = M.begin();
			int b = (*q).first;
			q ++;
			int z = (*q).first;
			int d = min(z, b + (k / x));
			if (d == b)
				break;
			k -= x * (d - b);
			cnt[b] = 0;
			M.erase({b, x});
			M.erase({d, cnt[d]});
			cnt[d] += x;
			M.insert({d, cnt[d]});
		}
		else{
			auto q = M.end();
			q --;
			int b = (*q).first;
			q --;
			int z = (*q).first;
			int d = max(z, b - (k / y));
			if (d == b)
				break;
			k -= y * (b - d);
			cnt[b] = 0;
			M.erase({b, y});
			M.erase({d, cnt[d]});
			cnt[d] += y;
			M.insert({d, cnt[d]});
		}
	}
	cout << (*M.rbegin()).first - (*M.begin()).first;
}
