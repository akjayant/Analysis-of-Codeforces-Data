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

const int N = 1e3 + 5;
char s[N];

int main()
{
	int T = _;
	while(T--)
	{
		int n = _;
		scanf("%s", s + 1);
		int tmp , ans = 0;
		for( int i = 1; i <= n; i++ ) 
			if(s[i] == '1')
				tmp = max(i, n - i + 1),
				ans = max(ans, tmp);
		ans <<= 1;
		ans = max(ans, n);
		cout << ans << ln;
	}
}