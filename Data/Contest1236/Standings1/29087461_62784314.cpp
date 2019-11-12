#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		ans = min(c / 2, b);
		c -= ans * 2;
		b -= ans;
		ans += min(a, b / 2);
		cout << ans * 3 << endl;
	}
}