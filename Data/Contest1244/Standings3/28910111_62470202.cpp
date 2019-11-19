#include <bits/stdc++.h>
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}
void cmax(int &x, int y){ if (x < y) x = y; }

int a[100130]; char c[293933];
int main(){
	int T; read(T);
	while (T--){
		int n; read(n);
		int Ans = n, lft = n + 1, rgt = -1;
		for (int i = 1; i <= n; i++){
			cin >> c[i], a[i] = c[i] - 48;
			if (a[i]) lft = min(lft, i), rgt = i;
		}
		if (lft == n + 1){ cout << Ans << '\n'; continue; }
		cmax(Ans, (n - lft + 1) * 2);
		cmax(Ans, rgt * 2);
		cout << Ans << '\n';
	}		
	return 0;
}
