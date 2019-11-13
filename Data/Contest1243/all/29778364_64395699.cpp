#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inc(i,n) for (int i=0;i<n;i++)
#define icc(i,n) for (int i=1;i<=n;i++)
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rpp(i,a,b) for (int i=a;i<=b;i++)
#define dec(i,n) for (int i=n-1;i>=0;i--)
#define dcc(i,n) for (int i=n;i;i--)
ll rd(){
	ll x=0,f=1;char c=getchar();
	while (!isdigit(c) && c!='-') c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
 
const int N=500010;
 
char a[100010],b[100010];
int df[100010];
 
int cnt[26];
 
int main(){
	int k=rd();
	while (k--){
		int n=rd();
		scanf("%s%s",a,b);
		memset(cnt,0,sizeof cnt);
		vector<pair<int,int> > ans;
		inc(i,n) cnt[a[i]-'a']++,cnt[b[i]-'a']++; 
		for (int i=0;i<26;i++) if (cnt[i]&1){
			puts("No");
			goto fail;
		}
		puts("Yes");
		inc(i,n){
			if (a[i]!=b[i]){
				rep(j,i+1,n){
					if (a[j]==a[i]) {ans.push_back({j,i});swap(a[j],b[i]); break;}
					if (b[j]==a[i]) {
						ans.push_back({i+1,j}); swap(a[i+1],b[j]);
						ans.push_back({i+1,i}); swap(a[i+1],b[i]);
						break;}
				}
			}
		}
		cout<<ans.size()<<'\n';
		for (auto p: ans){
			printf("%d %d\n",p.first+1, p.second+1);
		}
fail:;
	}	
	return 0;
}