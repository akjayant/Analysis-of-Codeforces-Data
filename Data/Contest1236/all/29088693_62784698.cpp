#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;

void solve(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int res=0;
		int d1=min(b,c/2);
		res+=3*d1;b-=d1;
		int d2=min(a,b/2);
		res+=3*d2;a-=d2;
		printf("%d\n",res);
	}
}
int main(){
	solve();
	return 0;
}