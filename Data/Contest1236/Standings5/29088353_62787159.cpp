#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int a, b, c; cin >> a >> b >> c;
		int ans = 0;
		for (int x = 0; x <= a; x++)
		{
			if (2*x > b)
				break;
			int cnt = 3*x;
			int tmp = b-2*x;
			int tt = min(tmp, c/2);
			cnt += tt*3;
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;	
}











