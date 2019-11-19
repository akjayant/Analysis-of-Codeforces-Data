#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
int ans;
char s[1010];
int f[1010][2];
int main(){
	int i,t,n;
	scanf("%d",&t);
	while(t--){
		int l=1e9,r=-1e9;
		ans=0;
		scanf("%d",&n);
		scanf("%s",s);
		f[0][0]=1;
		f[0][1]=1;
		if(s[0]=='1')l=0,f[0][0]=f[0][1]=2;
		for(i=1;s[i];i++){
			if(s[i]=='0'){
				f[i][0]=f[i-1][0]+1;
				f[i][1]=f[i-1][0]+1;
			}else{
				l=min(l,i);
				r=max(r,i);
				f[i][0]=max(f[i-1][1]+2,f[i-1][0]+1);
				f[i][1]=max(f[i-1][0]+2,f[i-1][1]+1);
			}
		}
		int ans=max(f[n-1][0],f[n-1][1]);
		ans=max(ans,r*2+2);
		ans=max(ans,2*n-(2*l));
		printf("%d\n",ans);
	}
	return 0;
}