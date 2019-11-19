#include <iostream>
using namespace std;
long long n,m,mod = 1e9+7;
long long f[200000][3][3];
int main()
{
		cin >> n >> m;
		f[1][0][1] = 1;
		f[1][1][1] = 1;
		for (int i = 2 ; i <= max(m,n) ; i++)
		{
				f[i][0][2] = f[i-1][0][1];
				f[i][0][1] = f[i-1][1][1] + f[i-1][1][2];
				
				f[i][1][2] = f[i-1][1][1];
				f[i][1][1] = f[i-1][0][1] + f[i-1][0][2];
				
				f[i][0][2] %= mod;
				f[i][0][1] %= mod;
				f[i][1][2] %= mod;
				f[i][1][1] %= mod;
		}

		long long kq = (f[m][0][2] + f[m][0][1]);
		kq %= mod;
		kq += f[m][1][1] + f[m][1][2];
		kq %= mod;
		kq += f[n][0][2] + f[n][0][1];
		kq %= mod;
		kq += f[n][1][1] + f[n][1][2];
		kq %= mod;
		kq -= 2;
		kq += mod;
		kq %= mod;
		cout <<kq;
}
