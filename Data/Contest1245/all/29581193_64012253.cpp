#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while (ch>'9' || ch<'0'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
const int N=1e5+5;
int gcd(int x,int y){
	if (!y) return x;
	return gcd(y,x%y);
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
    int T=read();
    while (T--){
    	int x=read(),y=read();
    	if (gcd(x,y)==1) puts("Finite");
    	else puts("Infinite");
    }
    return 0;
}
