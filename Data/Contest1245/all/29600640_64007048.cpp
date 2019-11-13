#include <bits/stdc++.h>
using namespace std;
#define re register
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> P;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int read() {
	int x = 0, f = 0; char ch = 0;
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
char ans[N];
int main(){
	int T = read();
	while (T--){
		int n = read();
		int a = read(), b = read(), c = read();
		string s; cin >> s;
		memset(ans, '0', sizeof(ans));
		int win = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'S' && a) a--, win++, ans[i] = 'R';
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'R' && b) b--, win++, ans[i] = 'P';
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'P' && c) c--, win++, ans[i] = 'S';	 
		if (win >= (n + 1) / 2) {
			puts("YES");
			for (int i = 0; i < s.size(); i++)
				if (ans[i] == 'S' || ans[i] == 'R' || ans[i] == 'P') putchar(ans[i]);
				else {
					if (a) a--, putchar('R');
					else if (b) b--, putchar('P');
					else if (c) c--, putchar('S');
				}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
