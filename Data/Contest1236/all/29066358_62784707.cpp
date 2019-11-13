#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
const int INF = 0x3f3f3f3f;
int t,a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		int ans1=min(c/2,b);
		b-=ans1;
		ans+=ans1*3;
		int ans2=min(b/2,a);
		ans+=ans2*3;
		printf("%d\n",ans);
	}
}