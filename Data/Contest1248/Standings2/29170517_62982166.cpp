#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

const int maxn = 100000 + 5;

int n;
int a[maxn];

inline void Solve (){
	sort(a + 1,a + n + 1);
	int x = 0,y = 0;
	for(int i = 1; i <= n / 2; i++){
		y += a[i];
	}
	for(int i = n / 2 + 1; i <= n; i++){
		x += a[i];
	}
	printf("%lld\n",x * x + y * y);
}

inline void Input (){
	n = read<int>();
	for(int i = 1; i <= n; i++){
		a[i] = read<int>();
	}
}

signed main(){
	Input();
	Solve();
	return 0;
}
