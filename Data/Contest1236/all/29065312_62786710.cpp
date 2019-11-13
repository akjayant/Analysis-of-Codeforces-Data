#include <bits/stdc++.h>
#define VI vector<int>
#define pb push_back
#define LL long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
int a, b, c;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		int C = min(c/2, b);
		int ans = 3*C;
		b -= C;
		C = min(a, b/2);
		ans += 3*C;
		printf("%d\n", ans);
	}
	
	return 0;
}