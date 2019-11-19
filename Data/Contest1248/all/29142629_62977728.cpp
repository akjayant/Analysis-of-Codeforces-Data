#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const long long ONE=1;
int K,N,M,P[MAXN],Q[MAXN];
int cnt1[5],cnt2[5];
long long Ans;
int main(){
	scanf("%d",&K);
	while(K--){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",&P[i]),cnt1[P[i]%2]++;
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
			scanf("%d",&Q[i]),cnt2[Q[i]%2]++;
		Ans=ONE*cnt1[0]*cnt2[0]+ONE*cnt1[1]*cnt2[1];
		printf("%lld\n",Ans);
	}
}
