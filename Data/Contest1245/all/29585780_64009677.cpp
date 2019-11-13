#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char str[105],ans[105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,a,b,c;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",str);
		int len=strlen(str);
		memset(ans,0,sizeof(ans));
		int cnt=0;
		for(int i=0;i<len;++i){
			if(str[i]=='R' && b){
				--b;
				ans[i]='P';
				++cnt;
			}
			if(str[i]=='S' && a){
				--a;
				ans[i]='R';
				++cnt;
			}
			if(str[i]=='P' && c){
				--c;
				ans[i]='S';
				++cnt;
			}
		}
		if(cnt>=(n+1)/2){
			puts("YES");
			for(int i=0;i<len;++i){
				if(0==ans[i]){
					if(a){
						--a;
						ans[i]='R';
						continue;
					}
					if(b){
						--b;
						ans[i]='P';
						continue;
					}
					if(c){
						--c;
						ans[i]='S';
						continue;
					}
				}
			}
			for(int i=0;i<len;++i) printf("%c",ans[i]);
			printf("\n");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}