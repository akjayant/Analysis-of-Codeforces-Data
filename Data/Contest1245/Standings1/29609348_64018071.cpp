#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 200005

inline int read()
{
    register int x = 0 , ch = getchar();
    while( !isdigit( ch ) ) ch = getchar();
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x;
}

int n,m;
int x,y;

int gcd(int x,int y) {
	if(x%y == 0) return y;
	return gcd(y,x%y);
}

void rd()
{
	cin >> n >> m;
	if(gcd(n,m) == 1) cout<<"Finite\n";
	else cout<<"Infinite\n";
}

signed main()
{
	int T;
	cin >> T;
	while(T --) {
		rd();
	}
	return 0;
}