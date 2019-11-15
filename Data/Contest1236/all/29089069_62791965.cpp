#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    for(; ch < '0' || ch>'9'; ch = getchar())
        if(ch == '-') f = -f;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}

inline void chkmin( int &a, int b ) { if(a > b) a = b; }

inline void chkmax( int &a, int b ) { if(a < b) a = b; }

#define _ read()

#define ln endl

const int mod = 1e9 + 7;

inline int power( int a, int b )
{
	int tmp = 1;
	while(b)
	{
		if(b & 1)
			tmp = 1ll * tmp * a % mod;
		b >>= 1; a = 1ll * a * a % mod;
	}
	return tmp;
}

int main()
{
	int a = _, b = _;
	int tmp = ( power(2, b) - 1 + mod ) % mod;
	int ans = power(tmp, a);
//	ans = (ans - 1 + mod )% mod;
	cout << ans << ln;
}