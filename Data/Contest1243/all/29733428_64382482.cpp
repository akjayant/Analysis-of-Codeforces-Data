#include<bits/stdc++.h>
using namespace std;
#define N 1005
char s[N],t[N];
int n,cnt[30];

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
		
		vector<pair<int,int> >ans;
		ans.clear();
		for(int i=1;i<=n;i++)if(s[i]!=t[i]){
			//先尝试把s[i]换成t[i]
			int flag=0;
			for(int j=i+1;j<=n;j++)	
				if(t[i]==t[j]){
					flag=1;
					ans.push_back(make_pair(i,j));
					swap(s[i],t[j]);
					break;
				}
			if(flag)continue;
			
			//尝试吧t[i]换成s[j] 
			for(int j=i+1;j<=n;j++)
				if(s[j]==s[i]){
					ans.push_back(make_pair(j,i));
					swap(s[j],t[i]);
					flag=1; 
					break;
				}
			if(flag)continue;
			
			//尝试吧s[i]换成s[j]
			for(int j=i+1;j<=n;j++)
				if(s[j]==t[i]){
					flag=1;
					ans.push_back(make_pair(i,i));
					swap(s[i],t[i]);
					ans.push_back(make_pair(j,i));
					swap(s[j],t[i]);
					break;
				}
			if(flag)continue;
			
			//尝试吧t[i]换成t[j] 
			for(int j=i+1;j<=n;j++)
				if(t[j]==s[i]){
					flag=1;
					ans.push_back(make_pair(i,i));
					swap(s[i],t[i]);
					ans.push_back(make_pair(i,j));
					swap(s[i],t[j]);
					break;
				}
		}
		
		puts("Yes");
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	}
}