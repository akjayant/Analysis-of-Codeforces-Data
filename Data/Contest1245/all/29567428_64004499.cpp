#include <iostream>
using namespace std;
long long f[1000001],kq = 1 , mod = 1e9+7;
string s;
int main()
{
		f[1] = 1;
		for (int i = 2 ; i <= 100000 ; i++)
		{
				if (i == 2)
				{
						f[i] = 2;
				}
				else
				{
						f[i] = f[i-1] + f[i-2];
				}
				f[i] %= mod;
		}
		int u = 0 , n = 0;
		cin >> s;
		s += '0';
		f[0] = 1;
		for (int i = 0 ; i < s.size() ; i++)
		{
				if (s[i] == 'm' || s[i] == 'w')
				{
						cout <<0;
						exit(0);
				}
				if (s[i] == 'u')
				{
						u++;
				}
				else
				{
						kq *= f[u];
						u = 0;
				}
				if (s[i] == 'n')
				{
						n++;
				}
				else
				{
						kq *= f[n];
						n = 0;
				}
				kq %= mod;
		}
		cout << kq;
}
