#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int x = a/c + (a%c>0?1:0);
	int y = b/d + (b%d>0?1:0);
	if(x+y>e)
		printf("-1\n");
	else
		printf("%d %d\n",x,y);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	
	return 0;
}
