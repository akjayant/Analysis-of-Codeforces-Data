#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;
int t,a,b,c;
int main(){
//	freopen("a.in","r",stdin); 
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		for(int i=0;i<=a;++i){
			if(2*i<=b){
				int yu=min(b-2*i,c/2);
				ans=max(ans,i+2*i+yu+2*yu);
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}
