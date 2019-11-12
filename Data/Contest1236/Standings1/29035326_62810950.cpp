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
int a,b,c;
int main()
{
	for (int T=rd();T--;){
		a=rd(),b=rd(),c=rd();
		int x=min(b,c/2),ans=x;
		b-=x;
		x=min(a,b/2),ans+=x;
		printf("%d\n",ans*3);
	}
	return 0;
}