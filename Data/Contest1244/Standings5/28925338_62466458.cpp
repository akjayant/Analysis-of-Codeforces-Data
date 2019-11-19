#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
int t,a,b,c,d,k;
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
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int aa=(a-1)/c+1,bb=(b-1)/d+1;
		if(aa+bb>k) printf("-1\n");
		else printf("%d %d\n",aa,bb);
	} 
	return 0;
}
