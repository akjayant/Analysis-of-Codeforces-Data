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
int a,b,c,d,k;
bool MOP2;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int A=(a+c-1)/c,B=(b+d-1)/d;
		if(A+B>k)puts("-1");
		else printf("%d %d\n",A,B);

	}
}

