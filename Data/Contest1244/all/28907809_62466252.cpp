#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 1003;
int t, n, mx, mn;
char str[N];
int main(){
	scanf("%d", &t);
	while(t --){
		scanf("%d%s", &n, str + 1); mx = 0; mn = n + 1;
		for(Rint i = 1;i <= n;i ++)
			if(str[i] == '1') mx = max(mx, i), mn = min(mn, i);
		if(mx == 0) printf("%d\n", n);
		else printf("%d\n", max(mx, n - mn + 1) * 2);
	}
}