#include<bits/stdc++.h>
using namespace std;

const int N=60;
int T,n,tot=0;
char s[N],t[N];
int a[N],b[N];
struct node{
	int x,y;
}op[N<<1];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		bool tf=true;tot=0;
		for(int i=0;i<26;i++){
			a[0]=0,b[0]=0;
			for(int j=1;j<=n;j++) if(s[j]!=t[j]){
				if(s[j]-'a'==i) a[++a[0]]=j;
				if(t[j]-'a'==i) b[++b[0]]=j;
			}
			if((a[0]+b[0])&1) {tf=false;break;}
			if(a[0]==b[0]) for(int i=1;i<=a[0];i++) op[++tot]=(node){a[i],a[i]},op[++tot]=(node){a[i],b[i]},swap(t[a[i]],t[b[i]]);
			else if(a[0]<b[0]){
				for(int i=1;i<=a[0];i++) op[++tot]=(node){a[i],a[i]},op[++tot]=(node){a[i],b[i]},swap(t[a[i]],t[b[i]]);
				for(int i=a[0]+1;i<=b[0];i+=2) op[++tot]=(node){b[i],b[i+1]},swap(s[b[i]],t[b[i+1]]);
			}
			else{
				for(int i=1;i<=b[0];i++) op[++tot]=(node){a[i],a[i]},op[++tot]=(node){a[i],b[i]},swap(t[a[i]],t[b[i]]);
				for(int i=b[0]+1;i<=a[0];i+=2) op[++tot]=(node){a[i+1],a[i]},swap(s[a[i+1]],t[a[i]]);
			}
		}
		if(!tf) printf("No\n");
		else{
			printf("Yes\n%d\n",tot);
			for(int i=1;i<=tot;i++) printf("%d %d\n",op[i].x,op[i].y);
		}
	}
}