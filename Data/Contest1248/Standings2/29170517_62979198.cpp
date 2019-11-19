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


int t;
int n,m;

inline void Solve (){
	while(t--){
		int p1 = 0,p2 = 0;
		int q1 = 0,q2 = 0;
		n = read<int>();
		for(int i = 1; i <= n; i++){
			int x;
			x = read<int>();
			if(x % 2){
				p1++;
			}else p2++;
		}
		m = read<int>();
		for(int i = 1; i <= m; i++){
			int x;
			x = read<int>();
			if(x % 2){
				q1++;
			}else q2++;
		}
		printf("%lld\n",p1 * q1 + p2 * q2);
	}
}

inline void Input (){
	t = read<int>();
}

signed main(){
	Input();
	Solve();
	return 0;
}
