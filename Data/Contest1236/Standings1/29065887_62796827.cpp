#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 100010
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n;

void read(int &X){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	X=x*f;
}

int main(){
	read(n);
	int ans[310][310];
	int cnt=n*n;
	for(int i=1;i<=n;i++){
		for(int j=i%2?n:1;1<=j&&j<=n;i%2?j--:j++)
			ans[j][i]=cnt--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}