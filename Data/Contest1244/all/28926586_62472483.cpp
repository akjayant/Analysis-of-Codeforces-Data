#include<bits/stdc++.h>
#define N ()
#define ll long long
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define bitdebug(x) cerr<<bitset<8>(x)<<endl
#define CM cerr<<(&MOP2-&MOP1)/1024.0/1024.0<<endl
using namespace std;
template <class T> T Min(T x,T y) {
	return x<y?x:y;
}
template <class T> T Max(T x,T y) {
	return x>y?x:y;
}
bool MOP1;
int T;
char A[1005];
bool MOP2;
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		int n;
		scanf("%d",&n);
		scanf("%s",A+1);
		ans=n;
		for(int i=1;i<=n;i++){
			if(A[i]=='1'){
				ans=Max(ans,n-i+1<<1);
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(A[i]=='1'){
				ans=Max(ans,i<<1);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

