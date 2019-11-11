#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

int T;
int a,b;

inline void Solve(){
	while(T--){
		a = read<int>();
		b = read<int>();
		if(__gcd(a,b) == 1){
			printf("Finite\n");
		}else printf("Infinite\n");
	}
}

inline void Input(){
	T = read<int>();
}

int main(){
	Input();
	Solve();
	return 0;
}
