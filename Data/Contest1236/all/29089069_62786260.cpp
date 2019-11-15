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

int main()
{
	int T = _;
	while( T-- )
	{
		int a = _,  b = _, c = _, ans = 0;
		for( int i = 0; i <= a; i++ ) 
		{
			if(b < 2 * i) break;
			int tmp = b - 2 * i;
			int tmp2 = min(tmp, c / 2);
			ans = max(ans, i + 2 * i + tmp2 + 2 * tmp2);
		}
		cout << ans << ln;
	}
}