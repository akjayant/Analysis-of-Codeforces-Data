#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int rd(){
	int x=0,flg=1;
	char c=getchar();
	for (;(c<48||c>57)&&c!='-';c=getchar());
	if (c=='-') flg=-1,c=getchar();
	for (;c>47&&c<58;x=x*10+c-48,c=getchar());
	return flg*x;
}
typedef long long LL;
typedef pair<int,int> pii;
const int md=1000000007;
int n,m;
int power(int x,int p,int num=1){
	for (;p;p>>=1,x=1ll*x*x%md)
		if (p&1) num=1ll*num*x%md;
	return num;
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",power(power(2,m)-1,n));
	return 0;
}