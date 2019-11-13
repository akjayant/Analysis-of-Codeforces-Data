#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<vector>
#define mod (1000000007)
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
 
int n,a,b,c;
int main()
{
	cin>>n;
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		int res=0;
		int nc=c/2;
		if(nc>b)
		res+=b+b*2,b=0;
		else  res+=nc*3,b-=nc;
		int nb=b/2;
		if(nb>a)
		res+=a+a*2,a=0;
		else  res+=nb*3,a-=nb;
		printf("%d\n",res);
	} 



	return 0;
}