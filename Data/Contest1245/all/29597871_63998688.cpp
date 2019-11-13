#include <iostream>
#include <algorithm>
#include <bitset> 
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>
#define int long long
#define double long double
using namespace std;

// const int MAXN =
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-5;

int n;

inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

signed main()
{
	int T = read();
    while(T--){
        int a, b;
        a = read(), b = read();
        if(__gcd(a, b) == 1){
            cout << "Finite" << endl;
        }
        else{
            cout << "Infinite" << endl;
        }
    }
	return 0;
}
