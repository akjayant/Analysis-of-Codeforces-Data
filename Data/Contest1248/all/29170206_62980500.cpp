#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 3;
int e,o,e0,o0,n,m;

signed main()
{
	int t; std::cin >> t;
	while(t--) {
		e = o = e0 = o0 = 0;
		std::cin >> n;
		for(int i = 1;i <= n;i++) {
			int tmp; std::cin >> tmp;
			if(tmp % 2) o++;
			else e++;
		}
		std::cin >> m;
		for(int i = 1;i <= m;i++) {
			int tmp; std::cin >> tmp;
			if(tmp % 2) o0++;
			else e0++;
		}

		std::cout << 1ll * e * e0 + o0 * o << "\n";
	}

	exit(0);
}
