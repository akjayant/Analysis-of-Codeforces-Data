#include <iostream>

using namespace std;

int main()
{
	int q = 0;
	cin >> q;

	int a, b, c, d, f;
	for (int k = 0; k < q; ++k)
	{
		cin >> a >> b >> c >> d >> f;
		int x = (a + c - 1) / c, y = (b + d - 1) / d;
		if (x + y > f)
			cout << "-1\n";
		else
			cout << x << " " << y << "\n";
	}

	return 0;
}