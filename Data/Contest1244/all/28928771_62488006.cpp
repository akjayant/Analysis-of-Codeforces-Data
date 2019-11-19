#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, a[100010];
ll k;
map<int, int> num;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) num[a[i]]++;
	map<int, int>::iterator ptr1 = num.begin(), ptr2 = num.end();
	ptr2--;
	int cnt1 = 0, cnt2 = 0;
	while (ptr1 != ptr2)
	{
		ll tl = ptr1->first, tr = ptr2->first;
		if (cnt1 + ptr1->second < cnt2 + ptr2->second)
		{
			cnt1 += ptr1->second;
			ptr1++;
			ll delta = 1ll * (ptr1->first - tl) * cnt1;
			if (delta <= k)
				k -= delta;
			else
			{
				ll ansl = tl + k / cnt1, ansr = tr;
				cout << ansr - ansl << endl;
				return 0;
			}
		}
		else
		{
			cnt2 += ptr2->second;
			ptr2--;
			ll delta = 1ll * (tr - ptr2->first) * cnt2;
			if (delta <= k)
				k -= delta;
			else
			{
				ll ansl = tl, ansr = tr - k / cnt2;
				cout << ansr - ansl << endl;
				return 0;
			}
		}
	}
	if (ptr1 == ptr2)
		cout << 0 << endl;
	return 0;
}
