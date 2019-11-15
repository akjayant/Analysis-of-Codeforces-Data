#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

const int N=305;
int n,s,d,m;
int a[N][N];

int main(){
	scanf("%d",&n);
	s=1;d=1;
	for(int j=1;j<=n;j++){
		for(int i=s;i>=1&&i<=n;i+=d) a[i][j]=++m;
		s=n+1-s;
		d=-d;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}