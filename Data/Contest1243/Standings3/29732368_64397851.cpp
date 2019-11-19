#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n;
set<long long> sta;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i * 1LL * i <= n; i++) {
		if (n%i == 0) {
			sta.insert(i);
			while (n%i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) sta.insert(n);
	if (sta.size() == 1) {
		cout << *(sta.begin()) << E;
	}
	else cout << 1 << E;
	//system("pause");
	return 0;
}