#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define mod 1000000007

using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll f[MAXN][2][2];

int main()
{
    int n,m;
    cin >> n >> m;
    f[1][0][0] = f[1][1][0] = 1;
    f[2][1][1] = f[2][1][0] = f[2][0][1] = f[2][0][0] = 1;
    for(int i = 3; i<=100000; i++)
    {
        f[i][1][0] += f[i-1][0][1]+f[i-1][0][0];
        f[i][1][1] += f[i-1][1][0];
        f[i][0][1] += f[i-1][1][0]+f[i-1][1][1];
        f[i][0][0] += f[i-1][0][1];
        f[i][0][0] %= mod;
        f[i][0][1] %= mod;
        f[i][1][0] %= mod;
		f[i][1][1] %= mod; 
	}
	ll ax = 0, ay = 0;
	ax = (f[n][0][0]+f[n][0][1]+f[n][1][0]+f[n][1][1])%mod;
	//cout << ax << endl;
	ay = (f[m][0][0]+f[m][0][1]+f[m][1][0]+f[m][1][1])%mod;
    cout << (ax+ay-2+mod)%mod << endl; 
	return 0;
}
