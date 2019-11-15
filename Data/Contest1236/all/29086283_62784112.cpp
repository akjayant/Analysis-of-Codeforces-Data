//I love Nanami ChiaKi
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9+7;
//const int N=;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		int mn=min(b,c/2);
		ans+=mn;
		b-=mn;
		mn=min(b/2,a);
		ans+=mn;
		printf("%d\n",ans*3);
	} 
	return 0;
}
/*
input:
*/

