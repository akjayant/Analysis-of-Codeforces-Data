#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T;
int N;
int cnt[2];
ll ans;

int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;cnt[0]=cnt[1]=0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++){int tmp;scanf("%d",&tmp);cnt[tmp&1]++;}
		scanf("%d",&N);
		for(int i=1;i<=N;i++){int tmp;scanf("%d",&tmp);ans+=cnt[tmp&1];}
		printf("%I64d\n",ans);
	}
	
    return 0;
}
