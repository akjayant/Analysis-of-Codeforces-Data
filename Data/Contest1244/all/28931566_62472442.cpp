#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
//#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
using pii = pair <ll,int>;
int T, n; 
char s[1005];

int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s+1);
		int l = 0, r = 0;
		for(int i=1; i<=n; i++)
			if(s[i] == '1') {
				l = i;
				break;
			}
		for(int i=n; i; i--)
			if(s[i] == '1') {
				r = i;
				break;
			}
		if(!l) printf("%d\n", n);
		else {
			int ans = n;
			ans = max(ans, l*2);
			ans = max(ans, r*2);
			ans = max(ans, (n-l+1)*2);
			ans = max(ans, (n-r+1)*2);
			printf("%d\n", ans);
		}
	}
}
