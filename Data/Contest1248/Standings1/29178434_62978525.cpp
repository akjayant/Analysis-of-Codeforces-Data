#include <iostream>
void solve()
{
	int cntp[2] = {};
	int n; for (std::cin >> n;n --;)
	{ int pi; std::cin >> pi,++ cntp[pi & 1]; }
	int cntq[2] = {};
	int m; for (std::cin >> m;m --;)
	{ int qi; std::cin >> qi,++ cntq[qi & 1]; }
	std::cout << static_cast <long long>(cntp[0]) * cntq[0] + static_cast <long long>(cntp[1]) * cntq[1] << '\n';
}
main()
{
	std::ios_base::sync_with_stdio(0),std::cin.tie(0);
	int t; for (std::cin >> t;t --;) solve();
}