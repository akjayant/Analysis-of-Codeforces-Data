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

int n,k;
int sum,S,T;

string s,t;

inline void Solve (){
	while(k--){
		n = read<int>();
		cin >> s >> t;
		sum = S = T = 0;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				sum++;
				if(!S){
					S = i;
				}else T = i;
			}
		}
		if(sum > 2 || sum == 1){
			puts("No");
		}else if(!sum){
			puts("Yes");
		}else{
			if(s[S] == s[T] && t[S] == t[T]){
				puts("Yes");
			}else puts("No");
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
