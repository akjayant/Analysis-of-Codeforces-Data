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
int main(){
	int t,a,b,c,d,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y<=k)printf("%d %d\n",x,y);
		else printf("-1\n");
	}
	return 0;
}