#include <iostream>
using namespace std;
int d[200000];
int main()
{
	int Ttest;
	cin >> Ttest;
	int dem = 0;
	int luot = 0;
	while (Ttest--)
	{
		dem = 0;
		luot++;
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= y; i++)
		{
			int k = (x*i) % y;
			if (d[k] != luot)
				dem++;
			d[k] = luot;
		}
		if (dem != y) cout << "Infinite" << endl;
		else cout << "Finite" << endl;
	}
	return 0;
}