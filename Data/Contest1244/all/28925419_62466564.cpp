#include<bits/stdc++.h>
#define N 
using namespace std;
bool cur1;
int a,b,c,d,K;
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);
	return;
}
bool cur2;
int main(){
//	printf("%lf MB\n",(&cur2-&cur1)/1024.0/1024);
	int T;
	Rd(T);
	while(T--){
		Rd(a);Rd(b);Rd(c);Rd(d);Rd(K);
		int L=(a+c-1)/c,R=(b+d-1)/d;
		if(L+R>K)puts("-1");
		else printf("%d %d\n",L,R);
	}
	return 0;
}