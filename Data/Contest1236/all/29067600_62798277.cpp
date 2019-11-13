#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
const int N=400;
int n,p[N][N];
int main(){
	scanf("%d",&n);
//	foru(i,1,n){
//		foru(j,1,n){
//			printf("%d ",n*(j-1)+(j+i-1)%n);
//		}
//		printf("\n");
//	}
	int i=1,j=1,cnt=1,x=1;
	while(1){
		p[i][j]=cnt++;
		i+=x;
		if(i==n+1){j++;i=n;x*=-1;};
		if(i==0){j++;i=1;x*=-1;};
		if(j>n)break;
	}
	foru(i,1,n){
		foru(j,1,n)printf("%d ",p[i][j]);
		printf("\n");
	}
	return 0;
}