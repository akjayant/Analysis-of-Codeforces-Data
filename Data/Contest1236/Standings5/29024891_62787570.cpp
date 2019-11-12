#include<cstdio>
#include<iostream>
#include<set>

using namespace std;
const int N=1e5+10;
int n;
int t;
int a,b,c;

int main(){
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d%d%d",&a,&b,&c);
		while(b>=1&&c>=2){
			b--;
			c-=2;
			ans+=3;
		}
		while(a>=1&&b>=2){
			a--;
			b-=2;
			ans+=3;
		}
		printf("%d\n",ans);
	}
	return 0;
} 