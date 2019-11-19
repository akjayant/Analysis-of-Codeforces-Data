#include<bits/stdc++.h>
using namespace std;
char s[10000];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		int ans = n;
		for(int i = 1; i <= n; i++){
			 if(s[i] == '1'){
			 	ans = max(ans, i + n-i+1);
			 	ans = max(ans, i*2);
				int j = n-i+1;
				ans = max(ans, j + n-j+1);
			 	ans = max(ans, j*2);
			 }
		}
		printf("%d\n", ans);
	}
}