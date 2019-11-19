#include <bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
const int N = 3e3 + 10;
const int M = 20;
#define lowbit(x) (x&(-x))
const int inf = 0x3f3f3f3f;
const ll INF = 100000000000000000;
const int mod = 998244353;
typedef pair<int, int> P;
#define eps 1e-6
int n, m;
int a, b, c, d, k;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> k;
		bool f = false;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <=  k - i; j++){
				if (f) break;
				if (i + j <= k)
				{
					if (i*c >= a&&j*d >= b){
						f = 1;
						printf("%d %d\n", i, j);
					}

				}

			}
			if (f) break;
		}
		if (!f){
			puts("-1");
		}
	}
	
	return 0;
}
/*

*/