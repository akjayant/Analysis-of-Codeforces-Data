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

int a[305][305];

int main()
{
	int n = _;
	int tmp = n * n;
	for( int j = 1; j <= n; j++ ) 
	{
		if(j&1)
			for( int i = 1; i <= n; i++ ) 
				a[i][j] = tmp--;
		else
			for( int i = n; i; i-- )
				a[i][j] = tmp--;
	}
	for( int i = 1; i <= n; i++, putchar('\n') ) 
		for( int j = 1; j <= n; j++, putchar(' ') ) 
			cout << a[i][j];
}