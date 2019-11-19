#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn=1005;
int n;
char s[maxn];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%s",&n,s);
		int ans=n;
		for (int i=0;i<n;i++){
			if (s[i]=='1'){
				ans=max(ans,(n-i)*2);
				ans=max(ans,(i+1)*2);
			}
		}
		cout << ans << '\n';
	}
}