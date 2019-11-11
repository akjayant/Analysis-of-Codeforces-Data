#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
void in(int &x){
	char ch=getchar();int flag=0;x=0;
	while(ch<'0'||ch>'9')flag|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
int a,b,t; 
int gcd(int x,int y){
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	in(t);
	while(t--){
		in(a);in(b);
		if(gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
}


