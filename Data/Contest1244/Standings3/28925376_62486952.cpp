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
		int a = _, b = _, c = _, d = _, e = _;
		int f = 0;
		for( int i = 1; i < e; i++ ) 
			if(i * c >= a && (e - i) * d >= b)
			{
				cout << i << " " << e - i << ln;
				f = 1;
				break;
			}
		if(!f)
			puts("-1");
	}
}