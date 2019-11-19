#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const long long ONE=1;
int N,A[MAXN],X,Y;
long long Ans;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]),Y+=A[i];
	sort(A+1,A+N+1);
	for(int i=1;i<=N/2;i++)
		X+=A[i];Y-=X;
	Ans=ONE*Y*Y+ONE*X*X;
	printf("%lld\n",Ans);
}