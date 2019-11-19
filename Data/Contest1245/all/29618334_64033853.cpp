#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>

const int MAX_D = 10;

int t[MAX_D][MAX_D], p[MAX_D * MAX_D];
long double f[MAX_D * MAX_D];
bool v[MAX_D * MAX_D];

void init()
{
	for (int i = 0, x = 0, y = 0, d = 1; i < MAX_D * MAX_D; ++i)
	{
		t[x][y] = i;
		if (y == 9 && d == 1) { x += 1; d = -1; }
		else if (y == 0 && d == -1) { x += 1; d = 1; }
		else y += d;
	}
}

long double solve(int i)
{
	if (i > 0 && !v[i])
	{
		v[i] = true;
		long double k = (long double)std::max(0, 6 - i) / 6;
		f[i] = k / ((long double)1 - k) + 1;
		for (int j = 1; j <= 6; ++j)
			if (i >= j)
				if (p[i - j] != -1)
					f[i] += std::min(solve(i - j), solve(p[i - j])) / std::min(i, 6);
				else
					f[i] += solve(i - j) / std::min(i, 6);
		//std::cout << "solve " << i << " = " << f[i] << '\n';
	}
	return f[i];
}

int main()
{
	std::cout << std::setprecision(10);
	init();
	memset(p, 0xff, sizeof(p));
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			int x; std::cin >> x;
			if (x) p[t[i][j]] = t[i - x][j];
		}
	std::cout << solve(99) << std::endl;
	return 0;
}
