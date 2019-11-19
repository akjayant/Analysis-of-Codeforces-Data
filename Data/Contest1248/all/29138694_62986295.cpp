#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, a[100009];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long tmp = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == n / 2) tmp = sum;
		sum += a[i];
	}
	long long ans = tmp *tmp + (sum - tmp)*(sum - tmp);
	cout << ans << E;
	//system("pause");
	return 0;
}