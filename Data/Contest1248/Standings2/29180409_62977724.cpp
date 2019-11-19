#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int j=0,o=0;
		for(int i=1;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp&1) j++;
			else o++;
		}
		scanf("%d",&n);
		int j2=0,o2=0;
		for(int i=1;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp&1) j2++;
			else o2++;
		}
		printf("%lld\n",1ll*j*j2+1ll*o*o2);
	}
	return 0;
}

