#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int x = a, y = b, z = c;
		int ans1 = 0, ans2 = 0;
		while(x && y > 1) ans1 += 3, x--, y -=2;
		while(y && z > 1) ans1 += 3, y--, z -=2;
		while(b && c > 1) ans2 += 3, b--, c -=2;
		while(a && b > 1) ans2 += 3, a--, b -=2;
		cout << max(ans1, ans2) << endl; 
	}
}