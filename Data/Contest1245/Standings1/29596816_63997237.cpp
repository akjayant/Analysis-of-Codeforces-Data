#include<bits/stdc++.h>
#define rep(q,a,b) for(int q=a,q##_end_=b;q<=q##_end_;++q)
#define dep(q,a,b) for(int q=a,q##_end_=b;q>=q##_end_;--q)
#define mem(a,b) memset(a,b,sizeof a )
using namespace std;
void in(int &r){
	static char c;
	r=0;
	bool flag=0;
	while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
	do r=(r<<1)+(r<<3)+(c^48);
	while(c=getchar(),isdigit(c));
	if(flag)r=-r;
}
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int main(){
	int T;
	in(T);
	int a,b;
	while(T--){
		in(a),in(b);
		if(gcd(a,b)!=1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}