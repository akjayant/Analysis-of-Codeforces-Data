#include<bits/stdc++.h>
using namespace std;
#define N 20005
char s[N],t[N];
int n,cnt[30];

int calc(){
	for(int i=1;i<=n;i++)
		if(s[i]!=t[i])return 0;
	return 1;
}

int main(){
	int T;cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		cin>>n;
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
		for(int i=1;i<=n;i++)cnt[t[i]-'a']++;
		
		int flag=0;
		for(int i=0;i<26;i++)if(cnt[i]%2!=0){
			flag=1;
		}
		if(flag){puts("No");continue;}
		
		vector<int>ans;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i]){
				ans.push_back(i);
			} 
		if(ans.size()>2){puts("No");continue;}
		else if(ans.size()==0){puts("Yes");continue;}
		else {
			int pos1=ans[0],pos2=ans[1];
			swap(s[pos1],t[pos2]);
			if(calc()){
				puts("Yes");continue;
			}
			swap(s[pos1],t[pos2]);
			swap(s[pos2],t[pos1]);
			if(calc()){
				puts("Yes");continue;
			}
			puts("No");
		}
		/*
		if(ans.size()<=1)puts("Yes");
		else puts("No");*/		
	/*	puts("Yes");
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	*/}
}