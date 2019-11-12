#include <bits/stdc++.h>
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

const int maxn = 1000 + 5;

int n,k;
int a[maxn];

inline void Solve (){
	while(k--){
		n = read<int>();
		for(int i = 1; i <= n; i++){
			a[i] = read<int>();
		}
		for(int i = n; i >= 1; i--){
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(a[j] >= i){
					cnt++;
				}
			}
			if(cnt >= i){
				printf("%d\n",i);
				break;
			}
		}
	}
}

inline void Input (){
	k = read<int>();
}

int main(){
	Input();
	Solve();
	return 0;
}
