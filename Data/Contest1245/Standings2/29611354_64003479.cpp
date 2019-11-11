//Coded by dst
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,cnt[200];
char st[200],ans[105];
string s;
int main(){
	st['S']='R';
	st['R']='P';
	st['P']='S';
	int i,n,sum;
	scanf("%d",&T);
	while(T--){
		memset(ans,0,sizeof(ans));
		sum=0;
		scanf("%d%d%d%d",&n,&cnt['R'],&cnt['P'],&cnt['S']);
		cin>>s;
		for(i=0;i<n;i++)
			if(cnt[st[s[i]]])
				cnt[st[s[i]]]--,sum++,ans[i]=st[s[i]];
		if(sum<(n-1)/2+1){
			printf("NO\n");
			continue;
		}
		for(i=0;i<n;i++)
			if(!ans[i]){
				if(cnt['R'])
					cnt['R']--,ans[i]='R';
				else if(cnt['P'])
					cnt['P']--,ans[i]='P';
				else
					ans[i]='S';
			}
		printf("YES\n%s\n",ans);
	}
	return 0;
}