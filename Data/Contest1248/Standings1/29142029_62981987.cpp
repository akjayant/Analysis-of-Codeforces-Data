#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;
ll sum,sum1;
int n,a[110000];
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;++i) sum1+=a[i];
	printf("%I64d\n",(sum-sum1)*(sum-sum1)+sum1*sum1);
	return 0;
}
