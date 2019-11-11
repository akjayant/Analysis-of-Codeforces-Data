#include <iostream>
#include <string>
#include <map>
using namespace std;
map <char, int> chuyen;
int d[3];
int main()
{
	int Ttest;
	cin >> Ttest;
	int n, a, b, c;
	string s,kq;
	int dem;
	//RPS
	//r - s
	//p - r
	//s - p
	d['R'] = 1;
	d['S'] = 0;
	d['P'] = 2;
	string p = "RPS";
	while (Ttest--)
	{
		cin >> n;
		cin >> d[0] >> d[1] >> d[2];
		s.clear();
		cin >> s;

		dem = 0;
		kq.clear();
		for (int i = 1; i <= n; i++) 
			kq.push_back('#');

		for (int i = 0; i < n; i++)
		{
			int chuyen = d[s[i]];
			if (d[chuyen]>0)
			{
				kq[i] = p[chuyen];
				dem++;
				d[chuyen]--;
			}
		}

		if (dem >= (n+1) / 2)
		{
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
			{
				if (kq[i] != '#') cout << kq[i];
				else
				{
					if (d[0]>0)
					{
						d[0]--;
						cout << p[0];
					}
					else
					if (d[1] > 0)
					{
						d[1]--;
						cout << p[1];
					}
					else
					if (d[2] > 0)
					{
						d[2]--;
						cout << p[2];
					}
				}
			}
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}