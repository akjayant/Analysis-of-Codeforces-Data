#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long temp[100010];

int main() {
	temp[1] = 2;
	temp[2] = 4;
	for (int i = 3; i <= 100000; i++)
	{
		temp[i] = (temp[i-1] + temp[i-2]) % MOD;
	}
	int n, m;
	cin>>m>>n;
	long long res;
	res = ((((temp[m] + temp[n])%MOD - temp[1])%MOD) + MOD)%MOD;
	cout<<res;
	
	return 0;
}