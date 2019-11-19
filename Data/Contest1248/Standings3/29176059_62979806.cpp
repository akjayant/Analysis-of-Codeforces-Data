#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
LL a,b,n,m,ans,T,x;
int main(){
	scanf("%d",&T);
	while(T--){
		a=b=ans=0;
		scanf("%d",&n);
		foru(i,1,n){
			scanf("%d",&x);
			if(x%2)a++;
			else b++;
		}
		scanf("%d",&m);
		foru(i,1,m){
			scanf("%d",&x);
			if(x%2)ans+=a;
			else ans+=b;
		}
		printf("%I64d\n",ans);
	}
}