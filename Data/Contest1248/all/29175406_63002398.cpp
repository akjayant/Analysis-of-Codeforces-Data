#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<cmath>
#include<map>
#include<set>
#include<deque>
using namespace std;
const int maxn = 1e5 + 10;
long long arr[maxn][4];
const int mod = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	arr[1][0] = arr[1][1] = 1;
	arr[2][0] = arr[2][1] = arr[2][2] = arr[2][3] = 1;
	for (int i = 3; i <= max(M, N); i++)
	{
		arr[i][0] = arr[i - 1][2] % mod;;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % mod;
		arr[i][2] = (arr[i - 1][1] + arr[i - 1][3]) % mod;
		arr[i][3] = arr[i - 1][1] % mod;
	}
	long long temp0 = 0, temp1 = 0;
	for (int i = 0; i < 4; i++)
	{
		temp0 += arr[N][i];
		temp1 += arr[M][i];
	}
	cout << ((temp0-2)+temp1)%mod;
}
