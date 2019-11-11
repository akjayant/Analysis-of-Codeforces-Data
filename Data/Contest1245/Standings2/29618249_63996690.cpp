#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
int t,a,b;
int read(){
    char c=getchar();int ans=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
    return ans;
}
int gcd(int x,int y){return x%y?gcd(y,x%y):y;}
int main(){
	t=read();
	while (t--){
		a=read(),b=read();
		printf("%s\n",gcd(a,b)!=1?"Infinite":"Finite");
	}
	return 0;
}
