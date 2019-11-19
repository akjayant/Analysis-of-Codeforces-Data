#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
int t,n;
char s[110000];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' or '9'<c) f=(c=='-'?-1:f),c=getchar();
	while('0'<=c and c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

int main(){
	srand(time(0));
//	freopen("a.in","r",stdin); 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;++i){
			if(s[i]=='1'){
				ans=max(ans,2*max(i,n-i+1));
			}
		} 
		printf("%d\n",ans);
	}
	
	return 0;
}
