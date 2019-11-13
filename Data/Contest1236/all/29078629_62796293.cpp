#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int MAXN=305;
int N,f=1,Cnt,A[MAXN][MAXN];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		if(f)for(int j=1;j<=N;j++)
			A[i][j]=++Cnt;
		else for(int j=N;j>=1;j--)
			A[i][j]=++Cnt;
		f=(f+1)%2;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<N;j++)
			printf("%d ",A[j][i]);
		printf("%d\n",A[N][i]);
	}
}
