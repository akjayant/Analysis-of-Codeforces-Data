#include <cstring>
#include <iostream>
using LL = long long;
bool bitx[30],bity[30];
LL F[31][2][2];
LL calc(int x,int y)
{
	if (x < 0 || y < 0) return 0;
	for (int i = 0;i < 30;++ i)
		bitx[i] = x >> i & 1,bity[i] = y >> i & 1;
	std::memset(F,0,sizeof F); F[30][1][1] = 1;
	for (int i = 29;~ i;-- i)
	{
		if (! (bitx[i] && bity[i])) F[i][1][1] += F[i + 1][1][1];
		F[i][1][0] += F[i + 1][1][0] * (1 + ! bitx[i]);
		if (bity[i]) F[i][1][0] += F[i + 1][1][1];
		F[i][0][1] += F[i + 1][0][1] * (1 + ! bity[i]);
		if (bitx[i]) F[i][0][1] += F[i + 1][1][1];
		F[i][0][0] += F[i + 1][0][0] * 3;
		if (bitx[i]) F[i][0][0] += F[i + 1][1][0] * 2;
		if (bity[i]) F[i][0][0] += F[i + 1][0][1] * 2;
		if (bitx[i] && bity[i]) F[i][0][0] += F[i + 1][1][1];
	}
	return F[0][0][0] + F[0][0][1] + F[0][1][0] + F[0][1][1];
}
void solve()
{
	int l,r; std::cin >> l >> r;
	std::cout << calc(r,r) + calc(l - 1,l - 1) - (calc(l - 1,r) << 1) << '\n';
}
main()
{
	int t; for (std::cin >> t;t --;) solve();
}