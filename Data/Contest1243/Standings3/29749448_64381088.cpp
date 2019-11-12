#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e4+10;
int tt;
int n;
char S[maxn],T[maxn];
//ull hs1[maxn],hs2[maxn],pw[maxn];
bool check() {
	for(int i=1;i<=n;++i) if(S[i]!=T[i]) return false;
	return true;
}
int main() {
	//pw[0]=1;
	//for(int i=1;i<maxn;++i) pw[i] = pw[i-1]*131;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		scanf("%s",S+1);
		scanf("%s",T+1);
		//for(int i=1;i<=n;++i) hs1[i] = hs1[i-1]*131 + S[i],hs2[i] = hs2[i-1]*131 + T[i];
		int flag = 1;
		for(int i=1;i<=n;++i) {
			if(S[i]!=T[i]) {
				flag = 0;
				for(int j = 1;j<=n;++j) {
					swap(S[i],T[j]);
					if(check()) {
						flag = 1;
						break;
					}
					swap(S[i],T[j]);
				}
				break;
			}
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}
