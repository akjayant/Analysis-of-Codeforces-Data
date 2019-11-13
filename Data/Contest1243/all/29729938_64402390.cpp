#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
const int INF = 1e9;
char t[maxn],s[maxn];
int n;
vector<int>v1,v2;
int cnt[26];

int main(){
	int q;scanf("%d",&q);
	while(q--){
		v1.clear();v2.clear();
		scanf("%d",&n);
		scanf("%s%s",s,t);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		int flag1=0;
		for(int i=0;i<26;i++){
			if(cnt[i]%2){
				flag1=1;break;
			}
		}
		if(flag1) {
			printf("No\n");continue;
		}
		while(1){
			int now,po;int flag=0;
			for(int i=0;i<n;i++){
				if(s[i]!=t[i]){
					now=s[i];po=i;flag=1;
					break;
				}
			}
			if(!flag) {
				printf("Yes\n");
				printf("%d\n",v1.size());
				for(int i=0;i<v1.size();i++){
					printf("%d %d\n",v1[i]+1,v2[i]+1);
				}
				break;
			}
			int flag2=0;
			for(int i=0;i<n;i++) if(t[i]==now&&s[i]!=now){
				v1.push_back(po);v2.push_back(po);
				swap(s[po],t[po]);
				v1.push_back(i);v2.push_back(po);flag2=1;
				swap(s[i],t[po]);
				break;
			}
			if(flag2) continue;
			for(int i=0;i<n;i++) if(s[i]==now&&i!=po&&t[i]!=now){
				v1.push_back(po);v2.push_back(i);
				swap(s[po],t[i]);
			}
		}
	}
}