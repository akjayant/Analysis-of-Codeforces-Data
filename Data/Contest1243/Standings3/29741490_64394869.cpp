#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;
int n;
char s[maxn],t[maxn];
int cs[30],ct[30];
vector<int>ans;

bool solve(){
	
	for(int i=0;i<26;i++)if((cs[i]+ct[i])&1)return false;
	
	for(int i=1;i<=n;i++){
		if(s[i]==t[i])continue;
		int p=-1;
		for(int j=i+1;j<=n;j++){
			if(s[j]==t[j])continue;
			if(s[j]==s[i] || t[j]==s[i]){
				p=j;
				break;	
			}
		}
		if(p==-1)return false;
		
		if(s[p]==s[i]){
			swap(s[p],t[i]);
			ans.push_back(p); ans.push_back(i);
		}
		else{
			swap(s[p],t[p]);
			ans.push_back(p); ans.push_back(p);
			swap(s[p],t[i]);
			ans.push_back(p); ans.push_back(i);
		}
	}
	
	for(int i=1;i<=n;i++)if(s[i]!=t[i])return false;
	return true;	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		memset(cs,0,sizeof(cs)); memset(ct,0,sizeof(ct)); ans.clear();
		scanf("%d",&n);
		scanf("%s",s+1);scanf("%s",t+1);
		for(int i=1;i<=n;i++)cs[s[i]-'a']++, ct[t[i]-'a']++;
		if(solve()){
			puts("Yes");
			printf("%d\n",(int)ans.size()/2);
			for(int i=0;i<(int)ans.size();i+=2)printf("%d %d\n",ans[i],ans[i+1]);
		}
		else puts("No");
	}
    return 0;
}
