#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
char s[N], t[N];
int main()
{
	int T;cin>>T;
	while(T--){
		int n, cnt = 0;scanf("%d", &n);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int t1 = 0, t2 = 0;
		for(int i = 1; i <= n; ++i){
			if(s[i] != t[i]) {
				cnt++;
				if(!t1) t1 = i;
				else if(!t2) t2 = i; 
			} 
		}
		if(cnt != 2) puts("No");
		else {
			if(s[t1] != s[t2] || t[t1] != t[t2]) puts("No");
			else puts("Yes");
		} 
	}
}
 