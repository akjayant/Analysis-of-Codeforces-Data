#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
const int INF = 1e9;
int n;
char s[maxn],t[maxn];
int main(){
	int q;scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		scanf("%s%s",s,t);
		char ch1,ch2;
		int ans=1;
		int flag=0;
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]&&!flag){
				flag=1;
				ch1=s[i];ch2=t[i];
			}else if(s[i]!=t[i]&&flag==1){
				if(s[i]==ch1&&t[i]==ch2){
					
				}else{
					ans=0;
					break;
				}
				flag=2;
			}else if(s[i]!=t[i]&&flag==2){
				ans=0;
				break;
			}
			
		}
		if(ans&&flag==2) printf("YES\n");
		else printf("NO\n");
		
	}
}