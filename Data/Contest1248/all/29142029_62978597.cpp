#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;
int t,n,a,s[10],m;
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s[0]=s[1]=0;
		for(int i=1;i<=n;++i) scanf("%d",&a),s[a%2]++;
		scanf("%d",&m);
		ll ans=0;
		for(int i=1;i<=m;++i) scanf("%d",&a),ans+=s[a%2];
		printf("%I64d\n",ans);
	}
	return 0;
}
