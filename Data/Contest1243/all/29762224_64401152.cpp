#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

struct node{
	int x,y;
}ans[1010];

ll T,n,sum[30],cnt;
char s[100],t[100];
bool cannot,flag;

int main(){
	T=read();
	while(T--)
	{
		n=read();cannot=cnt=0;memset(sum,0,sizeof(sum));
		scanf("%s",s+1),scanf("%s",t+1);
		for(int i=1;i<=n;i++)++sum[s[i]-'a'],++sum[t[i]-'a'];
		for(int i=0;i<26;i++)if(sum[i]&1){printf("No\n");cannot=1;break;}
		if(cannot)continue;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==t[i])continue;
			flag=0;
			for(int j=i+1;j<=n;j++)
				if(s[i]==s[j]){ans[++cnt].x=j,ans[cnt].y=i;swap(s[j],t[i]);flag=1;break;}
			if(!flag){
				for(int j=i+1;j<=n;j++){
					if(s[i]==t[j]){
						ans[++cnt].x=i+1,ans[cnt].y=j;swap(s[i+1],t[j]);
						ans[++cnt].x=i+1,ans[cnt].y=i;swap(s[i+1],t[i]);
						break;
					}
				}
			}
		}
		printf("Yes\n%d\n",cnt);
		for(int i=1;i<=cnt;i++)cout<<ans[i].x<<" "<<ans[i].y<<endl; 
	}return 0;
}
