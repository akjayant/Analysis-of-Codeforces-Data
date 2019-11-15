#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e4+10;
int tt;
int n;
char S[maxn],T[maxn];
vector<pair<int,int> > ans;
set<int> C1[141],C2[141];
int cnt[141];
void exChange(int pos,int i) {
	C1[S[pos]].erase(pos);
	C2[T[i]].erase(i);
	swap(S[pos],T[i]);
	C1[S[pos]].insert(pos);
	C2[T[i]].insert(i);
	ans.push_back(make_pair(pos,i));
}
int main() {
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		scanf("%s",S+1);
		scanf("%s",T+1);
		for(int i='a';i<='z';++i)  {
			C1[i].clear();C2[i].clear();
		}
		for(int i='a';i<='z';++i) cnt[i]=0;
		for(int i=1;i<=n;++i) cnt[S[i]]++,cnt[T[i]]++;
		int flag = 1;
		for(int i='a';i<='z';++i) {
			if(cnt[i]&1) flag=0;
		}
		if(flag==0) {
			puts("No");
			continue;
		}
		ans.clear();
		for(int i=1;i<=n;++i) C1[S[i]].insert(i);
		for(int i=1;i<=n;++i) C2[T[i]].insert(i);
		for(int i=1;i<=n;++i) {
			if(S[i]!=T[i]) {
				int pos = *(--C1[S[i]].end());
				if(pos > i) {
					ans.push_back(make_pair(pos,i));
					C1[S[i]].erase(pos);
					C2[T[i]].erase(i);
					swap(S[pos],T[i]);
					C1[S[pos]].insert(pos);
					C2[T[i]].insert(i);
				}
				else {
					pos = *(--C2[S[i]].end());
					assert(pos > i);
					exChange(n,pos);
					exChange(n,i);
				}
			}
		}
		puts("Yes");
		printf("%lu\n",ans.size());
		for(auto x : ans) {
			printf("%d %d\n",x.first,x.second);
		}
	}
	return 0;
}
