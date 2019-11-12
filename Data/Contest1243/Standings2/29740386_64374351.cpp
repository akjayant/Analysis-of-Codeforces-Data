#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[10005];
int main()
{
	cin >> k;
	while (k--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int ma = 1;
		for (int i = 0; i < n; i++)
			ma = max(ma, min(n - i, a[i]));
		cout << ma<<endl;
	}


}