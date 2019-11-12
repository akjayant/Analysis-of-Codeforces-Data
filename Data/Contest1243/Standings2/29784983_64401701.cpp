#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
char s[maxn],t[maxn];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){};
};
node ans[110];
int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		int cnt=0;
		int fg=1;
		scanf("%d",&n);
		scanf("%s",s),scanf("%s",t);
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				int ok=0;
				for(int j=i+1;j<n;j++){
					if(s[i]==s[j]){
						ans[cnt++]=node(j,i);
						ok=1;
						swap(s[j],t[i]);
						break;
					}
				}
				if(ok) continue;
				for(int j=i+1;j<n;j++){
					if(s[i]==t[j]){
						ans[cnt++]=node(i+1,j);
						swap(s[i+1],t[j]);
						ans[cnt++]=node(i+1,i);
						swap(s[i+1],t[i]);
						ok=1;
						break;
					}
				}
				if(ok) continue;
				fg=0;
				break;
			}
		}
		if(fg){
			printf("Yes\n");
			printf("%d\n",cnt);
			for(int i=0;i<cnt;i++){
				printf("%d %d\n",ans[i].x+1,ans[i].y+1);
			}
		}else{
			printf("No\n");
		}
	}
}