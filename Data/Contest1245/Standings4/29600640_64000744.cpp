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
int col[N]; 
int main(){
	int T = read();
	while (T--){
		int a = read(), b = read();
		if (__gcd(a, b) == 1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}


