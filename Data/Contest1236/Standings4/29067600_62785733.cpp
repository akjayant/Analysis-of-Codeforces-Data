#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
int T,a,b,c,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(2*b>=c){
			ans=c/2*3;
			b-=c/2;
			if(2*a>=b){
				ans+=b/2*3;
			}else{
				ans+=a*3;
			}
		}else ans=b*3;
		printf("%d\n",ans);
	}
}