#include <bits/stdc++.h>
using namespace std;

int n;
char s[300005];

namespace solver1{

	int qzh[300005];
	int ans;
	int ansi,ansj;

	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				swap(s[i],s[j]);
				int minx=0,cnt=0;
				for(int k=1;k<=n;k++){
					qzh[k]=qzh[k-1]+(s[k]=='('?1:-1);
					if(qzh[k]<minx){
						minx=qzh[k];
						cnt=1;
					}else if(qzh[k]==minx){
						cnt++;
					}
				}
				if(qzh[n]){
					cnt=0;
				}
				ans=max(ans,cnt);
				if(ans==cnt){
					ansi=i;
					ansj=j;
				}
				swap(s[i],s[j]);
			}
		}
		printf("%d\n",ans);
		printf("%d %d\n",ansi,ansj);
	}

}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n<=500){
		solver1::solve();
	}else{
	}
	return 0;
}