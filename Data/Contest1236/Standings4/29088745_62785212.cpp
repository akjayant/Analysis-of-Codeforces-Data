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

int t;

int main(){
	scanf("%d",&t);
	while(t--){
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a;i++) if(b>=i*2){
			int cur=i*3;
			int lb=b-i*2;
			cur+=min(lb,c/2)*3;
			ans=max(ans,cur);
		}
		printf("%d\n",ans);
	}
	return 0;
}