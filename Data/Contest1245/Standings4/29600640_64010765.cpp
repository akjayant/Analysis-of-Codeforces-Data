#include <bits/stdc++.h>
using namespace std;
#define re register
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> P;
const int N = 1e6 + 5, p = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int read() {
	int x = 0, f = 0; char ch = 0;
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
char s[N];
int f[N];
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) 
		if (s[i] == 'w' || s[i] == 'm') {
			puts("0"); return 0;
		}
	f[0] = 1;
	for (int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		if (s[i] == 'n' && s[i - 1] == 'n' || s[i] == 'u' && s[i - 1] == 'u') f[i] = (f[i] + f[i - 2]) % p;
	} 
	printf("%d\n", f[n]);
	return 0;
}
