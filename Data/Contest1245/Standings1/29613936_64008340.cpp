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

const int maxn = 100 + 5;

int T,n,a,b,c;
char s[maxn],ans[maxn];

inline void Solve(){
	while(T--){
		int alice = 0;
		memset(ans,0,sizeof(ans));
		n = read<int>();
		a = read<int>();
		b = read<int>();
		c = read<int>();
		scanf("%s",s + 1);
		for(int i = 1; i <= n; i++){
			if(s[i] == 'R' && b > 0){
				ans[i] = 'P';
				alice++;
				b--;
			}else if(s[i] == 'P' && c > 0){
				ans[i] = 'S';
				alice++;
				c--;
			}else if(s[i] == 'S' && a > 0){
				ans[i] = 'R';
				alice++;
				a--;
			}
		}
		if(alice >= ((n + 1) / 2)){
			printf("YES\n");
			for(int i = 1; i <= n; i++){
				if(ans[i]){
					printf("%c",ans[i]);
				}else{
					if(a){
						printf("R");
						a--;
					}else if(b){
						printf("P");
						b--;
					}else printf("S"),c--;
				}
			}
			puts("");
		}else printf("NO\n");
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
