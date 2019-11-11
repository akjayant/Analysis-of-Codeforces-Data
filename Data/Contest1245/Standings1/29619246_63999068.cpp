#include <string>
#include <iostream>
#include <algorithm>
void solve()
{
	int n,a,b,c; std::string s; std::cin >> n >> a >> b >> c >> s;
	int b_ = std::count(s.begin(),s.end(),'R');
	int c_ = std::count(s.begin(),s.end(),'P');
	int a_ = std::count(s.begin(),s.end(),'S');
	if (std::min(a,a_) + std::min(b,b_) + std::min(c,c_) >= n + 1 >> 1)
	{
		std::cout << "YES\n";
		std::string t(n,'.');
		for (int i = 0;i < n;++ i)
		{
			if (s[i] == 'S')
				if (a) t[i] = 'R',-- a;
			if (s[i] == 'R')
				if (b) t[i] = 'P',-- b;
			if (s[i] == 'P')
				if (c) t[i] = 'S',-- c;
		}
		for (int i = 0;i < n;++ i)
			if (t[i] == '.')
			{
				if (a) { t[i] = 'R',-- a; continue; }
				if (b) { t[i] = 'P',-- b; continue; }
				if (c) { t[i] = 'S',-- c; continue; }
			}
		std::cout << t << '\n';
	}
	else
		std::cout << "NO\n";
}
main()
{
	std::ios_base::sync_with_stdio(0),std::cin.tie(0);
	int t; for (std::cin >> t;t --;) solve();
}