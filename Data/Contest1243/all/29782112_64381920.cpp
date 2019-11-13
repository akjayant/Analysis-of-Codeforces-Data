#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	scanf("%d",&k);
	int n;
	char s[10010];
	char t[10010];
	char s1[10010];
	char t1[10010];
	while (k--){
		scanf("%d",&n);
		scanf("%s%s",s,t);
		int cnt=0;
		for (int i=0;i<n;i++){
			if (s[i]!=t[i]){
				s1[cnt]=s[i];
				t1[cnt]=t[i];
				cnt++;
			}
		}
		if (!cnt) printf("Yes\n");
		else{
			if (cnt==2){
				if (s1[0]==s1[1] && t1[0]==t1[1]) {
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
			else{
				printf("No\n");
			} 
		} 
	} 
	
	return 0;
}