/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<qpow((qpow(2,m)-1+mod)%mod,n);
	return 0;
}