#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define ll long long
#define mod 1000000007
using namespace std;
inline int qpow(int n,int w){
	int s[110],num=0;
	while(w>0) s[++num]=w%2,w/=2;
	int t=n,ans=1;
	if(s[1]) ans=n;
	for(int i=2;i<=num;++i){
		t=1ll*t*t%mod;
		if(s[i]) ans=1ll*ans*t%mod;
	}
	return ans;
}
int n,m;
int main(){
//	freopen("a.in","r",stdin); 
	scanf("%d%d",&n,&m);
	printf("%d\n",qpow(qpow(2,m)-1,n));
	return 0;
}
